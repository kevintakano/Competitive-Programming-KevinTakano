#include <cstdio>
#include <math.h>


int main()
{
	


	float L, C, R1,R2; 
	
	float D1,D2;
	

	float D; 

	float p1_x,p1_y,p2_x,p2_y;
	while(scanf("%f %f %f %f",&L,&C,&R1,&R2) == 4)
	{
		if(L == 0)
			return 0 ;
		D1 = R1*2;
		D2 = R2*2;
		
		p1_x = R1; p1_y =R1; 

		p2_x = L - R2; p2_y = C - R2; 
		D = R1 + R2;

		float D_ = sqrt( (p1_x - p2_x)*(p1_x - p2_x) + (p1_y - p2_y)*(p1_y - p2_y) );
		//printf("%f %f %f %f\n",L,C,R1,R2);
		//printf("%f %f\n",D_,D);
		if (L < D1 || C < D1 || L < D2 || C < D2 )
		{
			printf("N\n");
			continue;
		}
			

		if (D_ < D && L < (D1 + D2) && C < (D1 + D2))
		{
			printf("N\n");
		}else 
		{
			printf("S\n");
		}
	}

		


}