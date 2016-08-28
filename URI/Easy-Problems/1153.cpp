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

	int a = 0;

	cin >> a; 

	if(a == 1 || a == 0) 
	{
		printf("1\n");
	} else 
	{
		int fat = 1;

		while(a >= 1)
		{
			fat = fat*a; 
			a--;
		}

		printf("%d\n",fat);
	}

	return 0;
}