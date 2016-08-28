
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
#define FOR(i,N) for(int i =0;i < N;i++)


int main()
{

	int vet[1000];

	int N,K;

	cin >> N >> K;
	int first, second,k = 0;
	int third;
	FOR(i,N)
	{
		cin >> vet[i];
	}

	for(int i = 1; i < N - 1;i++)
	{
		first = vet[i-1];
		second = vet[i];
		third = vet[i+1];

		// printf("Atuais f,s,t %d,%d,%d\n",first,second,third);

		if(second < first && third > second)
		{
			// printf("Encontrei %d como PICO\n",first);
			k++;
		}
	}

	if((k+1) == K)
		printf("beautiful\n");
	else
		printf("ugly\n");

	return 0;
}