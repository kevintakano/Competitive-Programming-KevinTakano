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

	for(int k = 1; k <= N;k++)
	{
		printf("%d %d %d\n",k,k*k,k*k*k);
	}


	return 0;
}