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
	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int N1,D1, D2,N2; 
		char op;

		scanf("%d / %d %c %d / %d",&N1,&D1,&op,&N2,&D2);

		int N3,D3;

		int SN,SD;

		if(op == '+')
		{
			N3 = N1*D2 + N2*D1; 
			D3 = D1*D2;
		} else if(op == '-')
		{
			N3 = N1*D2 - N2*D1; 
			D3 = D1*D2;
		} else if(op == '*')
		{
			N3 = N1*N2;
			D3 = D1*D2;
		} else if(op == '/')
		{
			N3 = N1*D2;
			D3 = N2*D1;
		} 

		int divisor = __gcd(N3,D3);

		// cout << "divisor " << divisor << END;

		SN = N3 / divisor; 
		SD = D3 / divisor;

		if(SD < 0)
		{
			SN = SN * (-1);
			SD = SD * (-1);
		}

		printf("%d/%d = %d/%d\n",N3,D3,SN,SD);

	}


	return 0;
}