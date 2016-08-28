#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 
#include <algorithm>
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
	int a, b,c,d;

	cin >> c >> d;

	a = min(c,d);

	b = max(c,d);

	for(int i = a + 1 ; i < b; i++)
	{
		if(i % 5 == 2 || i % 5 == 3)
		{
			printf("%d\n",i);
		}
	}


	return 0;
}