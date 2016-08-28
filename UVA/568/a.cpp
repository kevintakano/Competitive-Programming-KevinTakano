#include <bits/stdc++.h>
#include <algorithm> 

using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define FOR(i,N) for(int i =0;i < N;i++)

const int MAXN = 1001, INF = 0x3f3f3f3f;;

#define MAX 1000000000000000000
typedef unsigned long long ll;

char last_non_digit_factorial(int k )
{

	ll p = 1;

	for(int i = k ; i >= 1; i--)
	{
		p = (p%MAX) * (i%MAX) % MAX ;
	}

	char string[200];

	sprintf(string,"%lld",p);

	int tam = strlen(string);

	printf("%s\n",string);

	int i;
	for(i = tam - 1; i >= 0  ; i--)
	{
		if(string[i] != '0')
		{
			HEY 
			break;
		}
	}

	return string[i];
}

int main()
{
	int N;



	while(cin >> N)
	{
		char c = last_non_digit_factorial(N);

		printf("N -> %c\n",c);
	}


	return 0;

}