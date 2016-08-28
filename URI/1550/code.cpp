
#include <bits/stdc++.h>

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

typedef  pair<int,int>  ii;

typedef struct n 
{
	int value, steps; 
}nodeType; 

int invert(int num1)
{
	int res = 0;

	int i = 10;

	while(num1 > 0)
	{		
		res = res * 10 + (num1 % 10);
		num1 = num1 / 10;
	}	

	return res; 
}

int main()
{

	int T;

	cin >> T;

	for(int i = 0; i <  T;i++)
	{	
		int num1,num2;

		queue< pair<int,int> > q; 

		set<int> visited; 

		cin >> num1 >> num2; 

		int final_cost = 1;
	
		q.push(ii(num1,0));
		visited.insert(num1);


		int larger = num1;

		while(!q.empty())
		{
			int current = q.front().first; 
			int cost = q.front().second;

			q.pop();

			// printf("current vertex = %d\n",current); 
			// printf("cost current vertex = %d\n",cost);
	
			int reverse = invert(current);
			int addtion = current + 1;

			// printf("	reverse vertex %d\n",reverse);
			// printf("	addtion vertex %d\n",addtion);

			final_cost = cost;

			if(current == num2)
			{
				break;
			}	

			// printf("Larger %d\n",larger);

			// getchar();

			auto it = visited.find(addtion);
			auto it2 = visited.find(reverse);
			
			if(it2==visited.end())
			{	
				// HEYA
				visited.insert(reverse);
				q.push(ii(reverse,cost+1));
			} 
			if(it==visited.end())
			{
				visited.insert(addtion);	
				q.push(ii(addtion,cost+1));
			} 
		}

		cout << final_cost << END;
	}


	

	return 0;
}