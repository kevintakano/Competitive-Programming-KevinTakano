#include <cstdio>
#include <cmath>

int main()
{
	
	double n,R,r;

	scanf("%lf %lf %lf",&n,&R,&r); 

	double alpha = 360.0/(2*n);  

	alpha = alpha * M_PI/180.0; 

	double A = r*r*sin(alpha)*cos(alpha)/2;

	double B = (R - r*cos(alpha))*r*sin(alpha)/2; 
	
	/*printf("%lf\n",alpha);	

	printf("%lf\n",r*cos(alpha));*/

	double final_area = n*(2*(A + B)); 

	printf("%.6lf\n",final_area); 

	printf("%lf\n",29321*283123*30.0);
	printf("%lf\n",29321.0*283123.0*30.0);

	return 0; 
}
