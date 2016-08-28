#include <cstdio>

int main()
{
	unsigned int A,B;

	while(scanf("%u %u",&A,&B)==2)
	{
		printf("%u\n",A ^ B);
	}

	return 0;
}