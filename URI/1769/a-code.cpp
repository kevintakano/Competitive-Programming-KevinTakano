
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
	char input[14];

	while(cin >> input)
	{
		int sum = 0;

		FOR(i,14)
		{
			if(input[i] == '-' || input[i] == '.') continue;
			
			sum += input[i] - '0';
		}

		int b1 = 0, b2 = 0;

		int k = 0;
		FOR(i,14 - 2)
		{	
			if(input[i] == '-' || input[i] == '.') continue;
			else 
			{
				// printf("multiplicando por %c\n",input[i]);

				b1 += (input[i]-'0')*(k+1); 
				// printf("	valor de b1 %d %d\n",b1,k+1);
				// printf("	valor de b2 %d %d\n",b2,9-k);
				b2 += (input[i]-'0')*(9 - k); 
				k++;
			}
			
		}
		b1 = b1 % 11; if(b1 == 10) b1 = 0;
		b2 = b2 % 11; if(b2 == 10) b2 = 0;

		// printf("Sum %d b1 %d b2 %d\n",sum,b1,b2);

		if(b1 == (input[14-2]-'0') && b2 == (input[14-1]-'0'))
		{
			cout << "CPF valido" << END;
		} else 
		{
			cout << "CPF invalido" << END;
		}

	}


	return 0;
}