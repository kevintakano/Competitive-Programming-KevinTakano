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

	double N;

	cin >> N;
	cout << "NOTAS:" << endl;

	int N2 = N;

	printf("%d nota(s) de R$ 100.00\n", (int) N/100);
	printf("%d nota(s) de R$ 50.00\n",(int)(N2%100)/50);
	printf("%d nota(s) de R$ 20.00\n",(int)((N2%100)%50)/20);
	printf("%d nota(s) de R$ 10.00\n",(int)( ((N2%100)%50)%20)/10 );
	printf("%d nota(s) de R$ 5.00\n", (int)((( (N2%100)%50)%20)%10)/5);
	printf("%d nota(s) de R$ 2.00\n", (int)( ((((N2%100)%50)%20)%10)%5)/2 );

	cout << "MOEDAS:" << endl;

	int valor = (N - N2) * 100 ;
	// cout << valor << endl;


	printf("%d moeda(s) de R$ 1.00\n",(int) (((((N2%100)%50)%20)%10)%5)%2);
	printf("%d moeda(s) de R$ 0.50\n", (int) valor  / 50 );
	printf("%d moeda(s) de R$ 0.25\n",(int) (valor % 50) / 25 );
	printf("%d moeda(s) de R$ 0.10\n",(int) (valor % 50) % 25 / 10 );
	printf("%d moeda(s) de R$ 0.05\n", (int) (valor % 50) % 25 % 10 / 5  );
	printf("%d moeda(s) de R$ 0.01\n", (int) (valor % 50) % 25 % 10 % 5 / 1 );

	return 0;
}