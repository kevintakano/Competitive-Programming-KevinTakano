
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

int main()
{
	int N;

	cin >> N;

	for(int i = 0; i < N;i++)
	{
		int A;

		cin >> A;

		if(A > 0 && A % 2 == 0)
		{
			printf("EVEN POSITIVE\n");	
		}else
		if(A < 0 && A % 2 == 0)
		{
			printf("EVEN NEGATIVE\n");	
		}else 
		if(A  < 0 && (A % 2) != 0 )
		{
			printf("ODD NEGATIVE\n");	
		}else
		if(A > 0 && A % 2 == 1)
		{
			printf("ODD POSITIVE\n");	
		}else
		{
			if(A == 0)
			{
				printf("NULL\n");
			}
		}	
	}


	return 0;
}