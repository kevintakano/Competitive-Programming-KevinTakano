#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int cod1, n1;
	double v1;

	int cod2, n2;
	double v2;
	
	cin >> cod1 >> n1 >> v1; 
	cin >> cod2 >> n2 >> v2;

	printf("VALOR A PAGAR: R$ %.2lf\n",n1*v1 + n2*v2);

	return 0;
}