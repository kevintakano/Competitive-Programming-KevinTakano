from math import *

while True:
	try:
			
		line = input()
		split_line = line.split()
		L = int (eval(split_line[0]))
		C = int (eval(split_line[1]))
		R1 = int (eval(split_line[2]))
		R2 = int (eval(split_line[3]))
		D1 = R1*2
		D2 = R2*2

		D = R1 + R2 

		p1 = (R1,R1)
		p2 = (L-R2,(C-R2))
		print("L ",L,"R2",R2,"p2",p2)
		input()
		
		D_ = sqrt( (p1[0]-p2[0])*(p1[0]-p2[0]) + (p2[1]-p1[1])**2 )
		print(p1,p2)
		input()
		print(D,D_)
		
		if(D_ < D or L < D1 or C < D1 or L < D2 or C < D2 and L < D1 + D2 and C < D1 + D2):
			print("N")
		else: 
			print("S")



	except:
		break
