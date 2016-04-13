#!/usr/bin/ruby

type  = ARGV[0]
size  = ARGV[1].to_i
total = ARGV[2].to_i

tab = []
for i in 0...total
	tab << i
end

i = size
j = total

if(type == "compact")
	r = 0
	k = 0
	while i > 0
		print tab[r].to_s+' '
		tab[r] = nil
		r += 8
		k += 1
		if k == 16
			break
		end
	end
	tab.compact!
end

while i > 0
	r = (rand*j).to_i
	print tab[r].to_s+' '
	tab[r] = tab[j-1]
	i -= 1
	j -= 1
end
