#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")

#define FOR(i,N) for(int i = 0; i < N; i++)

int main()
{

	int N;

	cin >> N;

	FOR(i,N)
	{
		int A;

		cin >> A;

		int sum  = 0;

		for(int k = 1; k < A ;k++)
		{
			if(A % k == 0)
			{
				sum += k; 
			}
		}

		if(sum == A)
		{
			printf("%d eh perfeito\n",A);
		} else 
		{
			printf("%d nao eh perfeito\n",A);
		}
	}

	return 0;
}