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

	int N;

	cin >> N;
	cout << N << endl;
	printf("%d nota(s) de R$ 100,00\n",N/100);
	printf("%d nota(s) de R$ 50,00\n",(N%100)/50);
	printf("%d nota(s) de R$ 20,00\n",((N%100)%50)/20);
	printf("%d nota(s) de R$ 10,00\n",( ((N%100)%50)%20)/10 );
	printf("%d nota(s) de R$ 5,00\n", ((( (N%100)%50)%20)%10)/5);
	printf("%d nota(s) de R$ 2,00\n", ( ((((N%100)%50)%20)%10)%5)/2 );
	printf("%d nota(s) de R$ 1,00\n", (( (((N%100)%50)%20)%10)%5)%2 );

	return 0;
}