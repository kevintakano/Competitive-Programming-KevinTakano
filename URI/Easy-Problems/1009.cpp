#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	char string[100];

	double salario, totalvendas;

	cin >> string; 

	cin >> salario >> totalvendas;

	printf("TOTAL = R$ %.2lf\n",salario + ( totalvendas * 15 )/100);



	return 0;
}