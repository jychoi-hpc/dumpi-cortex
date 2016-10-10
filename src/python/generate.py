import yaml
import re

template = open('template.cpp').read()

def write_file(filename,content):
  output = open('gen/'+filename,'w+')
  output.write(content)
  output.close()

def basic_type_convertor(n,t):
  return '    args["'+n+'"]\t= prm->'+n+';\n'

def dumpi_status_convertor(n,t):
  return '    args["'+n+'"]\t= *(prm->'+n+');\n'

def string_convertor(n,t):
  return '    args["'+n+'"]\t= std::string(prm->'+n+');\n'

def array_convertor(n,t):
  m = re.match('(\w+)\[(\w+)\]',t)
  base = m.group(1)
  idx  = m.group(2)
  tmp = '    args["'+n+'"]\t= stl_vector_to_py_list('
  tmp = tmp + 'std::vector<'+base+'>(prm->'+n+','
  tmp = tmp + 'prm->'+n+'+prm->'+idx+'));\n'
  return tmp

def array_of_string_convertor(n,t):
  m = re.match('(\w+)\[(\w+)\]',t)
  idx  = m.group(2)
  tmp = '     { bp::list l; for(int i=0; i < prm->'+idx+'; i++) l.append(std::string(prm->'+n+'[i]));\n'
  tmp = tmp + '     args["'+n+'"]\t= l; }\n'
  return tmp

def pointer_converter(n,t):
  return '#warning "Pointer found for name '+n+' of type '+t+'"\n'

def struct_convertor(n,t):
  return '#warning "Object '+n+' of type '+str(t)+' should be handled here"\n'

def create_convertor_for(op,v):
  tmp = '\n'
  for arg in v:
    n = arg['name']
    t = arg['type']
    if not isinstance(t,basestring):
      tmp += struct_convertor(n,t)
    elif t.find('*') != -1 and t.find('dumpi_status*') == -1:
      tmp += pointer_converter(n,t)
    elif (t.find('[') != -1) and (t.find('string') != -1):
      tmp += array_of_string_convertor(n,t)
    elif (t.find('string') != -1):
      tmp += string_convertor(n,t)
    elif t.count('[') == 1:
      tmp += array_convertor(n,t)
    elif t.find('dumpi_status*') != -1:
      tmp += dumpi_status_convertor(n,t)
    elif t.find('*') == -1 and t.find('[') == -1:
      tmp += basic_type_convertor(n,t)
    else:
      tmp += '#warning "Object '+n+' of type '+str(t)+' should be handled here"\n'
  return tmp
      

'''
     if isinstance(arg['type'],basestring):
       if arg['type'].find('*') == -1:
         tmp = tmp+'    '+'args["'+arg['name']+'"]\t= prm->'+arg['name']+';\n'
       elif arg['type'] == 'dumpi_status*':
	 tmp = tmp + '#warning "A dumpi_status* should be handled here"\n'
         tmp = tmp+'    '+'args["'+arg['name']+'"]\t= *(prm->'+arg['name']+');\n'
       elif arg['type'] == 'char*':
         tmp = tmp+'    '+'args["'+arg['name']+'"]\t= std::string(prm->'+arg['name']+');\n'
       elif arg['type'].find('**') == -1:
         ttype = re.match('(\w+)\*',arg['type']).group(1)
         tmp = tmp+'    '+'args["'+arg['name']+'"]\t= stl_vector_to_py_list(std::vector<'+ttype+'>(prm->'+arg['name']+',prm->'+arg['name']+'+x));\n'
       else:
         tmp = tmp + '#warning "An object of type '+arg['type']+' should be handled here"\n'
	 tmp = tmp+'    '+'// '+'args["'+arg['name']+'"]\t= prm->'+arg['name']+';\n'
     else:
       tmp = tmp + '#warning "Object '+arg['name']+' of type '+str(arg['type'])+' should be handled here"\n'
  return tmp
'''

def generate(op,v):
  print "======= Generating ",op

  mpiname  = op[2:]
  filename = mpiname+".cpp"
  if(mpiname.find('mpio_') != -1):
    MPI_Name = re.sub('(mpio_\S)(\w+)', lambda m: m.group(1).upper()+m.group(2), mpiname)
  else:
    MPI_Name = re.sub('(mpi_\S)(\w+)', lambda m: m.group(1).upper()+m.group(2), mpiname)

  tmp = template.replace('%%dumpi_operation%%',op)
  tmp = tmp.replace('%%MPI_Operation%%',MPI_Name)
  convertor = create_convertor_for(op,v)
  tmp = tmp.replace('%%convertor%%', convertor)
  
  write_file(filename,tmp)
  

doc = open('operations.yml')
content = yaml.load(doc.read())

for x in content:
  op,v = x.iteritems().next()
  generate(op,v)
