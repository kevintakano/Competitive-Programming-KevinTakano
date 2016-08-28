#include <cstdio>

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a; 
	}
	else 
	{
		return gcd(b,a%b);
	}
}
/*
gcd(5,10)
10,(5%10)->10,(5)
5,10%5->5,0
*/


int main()
{

	int T;

	scanf("%d",&T);

	for(int i = 0 ; i < T;i++)
	{
		int F1,F2;

		scanf("%d %d",&F1,&F2);

		int res = gcd(F1,F2);

		printf("%d\n",res);
	}

	return 0;
}