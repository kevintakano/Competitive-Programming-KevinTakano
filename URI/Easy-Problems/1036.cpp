#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");

int main()
{

	double A,B,C;

	cin >> A >> B >> C;

	double delta = B*B - 4.0*A*C;

	if(delta < 0 || A == 0)
	{
		printf("Impossivel calcular\n");
	} else 
	{
		double r1 = (-B + sqrt(delta) )/2.0*A ;
		double r2 = (-B - sqrt(delta) )/2.0*A ;
		
		printf("R1 = %.5lf\n",r1/100.0);
		printf("R2 = %.5lf\n",r2/100.0);

	}



	return 0;
}