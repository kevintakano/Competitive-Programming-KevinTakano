p = open("res","r")
for line in p:
	n = line.split(' \n')
	a = n[0]
	b = n[1]
	print(n)
	if(a == b):
		print("CERTINHO")
	else:
		print("xablau a = ",a,"b = ",b)
