#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 

#include <queue> 

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");

int main()
{
	int tam1,tam2,tam3,tam4,tam5;

	int MAT[10][10];

	cin >> tam1; 

	for(int i = 0; i < tam1; i++)
	{
		cin >> MAT[0][i];
	}

	cin >> tam2;

	for(int i = 0; i < tam2; i++)
	{
		cin >> MAT[1][i];
	}

	cin >> tam3;

	for(int i = 0; i < tam3; i++)
	{
		cin >> MAT[2][i];
	}

	cin >> tam4;

	for(int i = 0; i < tam4; i++)
	{
		cin >> MAT[3][i];
	}

	cin >> tam5;

	for(int i = 0; i < tam5; i++)
	{
		cin >> MAT[4][i];
	}

	int larger_sum = 0;

	int sum = 0;

	int K ; cin >> K;

	priority_queue<int> q;

	for(int i = 0 ; i < tam1; i++)
	{
		for(int j = 0; j < tam2; j++)
		{
			for(int k = 0; k < tam3; k++)
			{
				for(int l = 0; l < tam4; l++)
				{
					for(int m = 0; m < tam5; m++)
					{
						sum = MAT[0][i] + MAT[1][j] + MAT[2][k] + MAT[3][l] + MAT[4][m];

						// larger_sum = sum;

						q.push(sum);

					}
				}
			}
		}
	}

	int i = 0; 

	int sum2 = 0;


	while(!q.empty() && i < K)
	{	

		sum2 += q.top(); q.pop();
		i++;
		}

	cout << sum2 << endl;

	return 0;
}