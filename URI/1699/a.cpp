#include <cstdio>
#include <iostream>
#include <vector> 
#include <algorithm> 

#define ENDLINE printf("\n");
#define END ('\n')
#include <cmath>

#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
using namespace std;

bool isPerfectSquare(long long n){
    long long squareRootN=(long long)round((sqrt(n)));

    if(squareRootN*squareRootN == n) {
        return true; 
    }
     else {
        return false; 
     }
 }

int main()
{
	while(1)
	{
		int N;

		cin >> N;

		if(N == 0) break;

		int count = 0;

		for(int i = 0; i < N;i++)
		{
			long long value ; 
			cin >> value ;


			if( isPerfectSquare(value) ) // se é um quadrado perfeito, então o n de divisores é impar.
			{
				count += 1;
			}
		}

		if(count % 2 != 0)
		{
			cout << "Annie" << END;
		} else 
		{
			cout << "Garen" << END;

		}



	}

	return 0;
}