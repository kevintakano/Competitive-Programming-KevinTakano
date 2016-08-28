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
#define END ("\n")

int main()
{
	int N,M;

	cin >> N >> M;

	int P1, P2;

	for(P1 = N; P1 >= 2; P1--)
	{
		int count = 0; 

		int ehprimo = 1;

		for(int k = 2 ;k <= P1/2; k++)
		{
			if(P1 % k == 0){
				ehprimo = 0;
				break;
			}
		}
		if(ehprimo) break;
	}

	for(P2 = M; P2 >= 2; P2--)
	{
		int count = 0; 

		int ehprimo = 1;

		for(int k = 2 ;k <= P2/2; k++)
		{
			if(P2 % k == 0){
				ehprimo = 0;
				break;
			}
		}
		if(ehprimo) break;
	}
/*
	cout << P1 << END;
	cout << P2 << END;
*/
	cout << P1 * P2 << END;


	return 0;
}