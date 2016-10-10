class MyTranslator():

    def MPI_Bcast(self, thread, **args):
        for k,v in args:
           print k, " = ", str(v)
