
#include <bits/stdc++.h>


using namespace std; 

#define MAX 12
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

	char  op;

	cin >> op;

	double M[MAX][MAX];

	for(int i = 0; i < MAX;i++)
	{
		for(int j = 0; j < MAX;j++)
		{
			cin >> M[i][j];
			// M[i][j] = 1;
		}
	}

	double S = 0;

	double count = 0;

	for(int i = 0; i < MAX;i++)
	{
		for(int j = i + 1; j < MAX;j++)
		{
			// printf("Estou lendo %d,%d\n",i,j);

			S += M[i][j];
			count++;
		}
	}

	// cout << "count " << count << END;

	if(op == 'S')
	{
		printf("%.1f\n",S);
	}else
	{
		printf("%.1f\n",S/count);

	}



	return 0;
}