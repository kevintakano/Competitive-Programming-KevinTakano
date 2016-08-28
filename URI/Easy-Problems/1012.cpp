#include <cstdio>
#include <iostream>
#include <vector> 
#include <algorithm> 

#define ENDLINE printf('\n');
#define END ('\n')
#include <cmath>

using namespace std;

int main()
{

	double A,B,C;

	cin >> A >> B >> C;

	printf("TRIANGULO: %.3lf\n", A*C/2.0);
	printf("CIRCULO: %.3lf\n", 3.14159 * C * C);
	printf("TRAPEZIO: %.3lf\n",(A + B)*C/2);
	printf("QUADRADO: %.3lf\n",B*B);
	printf("RETANGULO: %.3lf\n",A*B);
	

	return 0;
}