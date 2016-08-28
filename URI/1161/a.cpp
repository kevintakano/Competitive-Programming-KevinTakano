#include <cstdio>

	
unsigned long long fat(int n)
{
	if(n == 0 || n == 1)
	{
		return 1; 
	}

	long long unsigned t = 1; 

	for(int i = n; i >= 2; i--)
	{
		t *= i; 
	}


	return t; 
}

int main()
{
	int N,M;
	
	scanf("%d %d",&N,&M);

	int res; 

	do
	{
		

		unsigned  long long int f = fat(N) + fat(M);

		printf("%llu\n",f); 

		res = scanf("%d %d",&N,&M);

	}while(res == 2);

	return 0;
}