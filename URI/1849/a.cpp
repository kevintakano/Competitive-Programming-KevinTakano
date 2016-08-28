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
#define HEY2 printf("	2|HEY\n");
#define HEY3 printf("	3|	|HEY\n");
#define END ("\n")

int main()
{

	int L1,C1,L2,C2;

	cin >> L1 >> C1 >> L2 >> C2; 

	int res;


	if(L1 < C1) // se estiver em pé, deixa deitado
	{
		int aux  = L1;
		L1 = C1;
		C1 = aux;
	}
	if(L2 < C2)
	{
		int aux  = L2;
		L2 = C2;
		C2 = aux;	
	}

	if(L1 < L2)
	{
		int aux = L1;
		L1 = L2;
		L2 = aux;

		 aux = C1;
		C1 = C2;
		C2 = aux;
	}

	// printf("L2 = %d\n",L2);;

	if((C1 + C2) <= L2 )
	{
		res = (C1+C2);
	} else if( (C1 + C2) > L2)
	{

		res = L2;
	}else 
	if((C1 + C2) >= (L1) && L1 == L2)
	{

		res = L1;
	}

	else 
	{

		if(L1*C1 > L2*C2)
		{
			HEYA
			res = min(L1,C1);
		} else 
		{
			HEYB
			res = min(L2,C2);
		}
	}

	cout << res*res << END;



	return 0;
}