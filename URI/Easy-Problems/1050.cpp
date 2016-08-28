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
	int N;

	cin  >> N;

	if(N == 61)
	{
		cout << "Brasilia" << END;
	} else 
	if(N == 71)
	{
		cout << "Salvador" << END;
	}else 
	if(N == 11)
	{
		cout << "Sao Paulo" << END;
	}else 
	if(N == 21)
	{
		cout << "Rio de Janeiro" << END;
	}else 
	if(N == 32)
	{
		cout << "Juiz de Fora" << END;

	}else 
	if(N == 19)
	{
		cout << "Campinas" << END;
	}else if(N == 27)
	{
		cout << "Vitoria" << END;
	}else 

	if(N == 31)
	{
		cout << "Belo Horizonte" << END;
	}	
	else 
	{
		cout << "DDD nao cadastrado" << END;
	}

	return 0; 
}