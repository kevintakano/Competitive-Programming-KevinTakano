#include <cstdio>
#include <cstring>
#include <set>

#define DBUG1 printf("DBUG 1\n");
#define DBUG2 printf("DBUG 2\n");
#define DBUG3 printf("DBUG 3\n");

using namespace std;

void print_set(set<int> pset)
{
	for(auto &it : pset)
	{
		printf("[%d]",it); 
	}
	printf("\n");
}

int main()
{
	int A,B;

	scanf("%d %d",&A,&B);

	do
	{


		set<int> a_cards; 

		set<int> b_cards; 

		set<int> intersection_cards;

		for(int i = 0 ;i < A;i++)
		{
			int value; 

			scanf("%d",&value); 

			a_cards.insert(value);
		}

		for(int i = 0 ;i < B;i++)
		{
			int value; 

			scanf("%d",&value); 

			b_cards.insert(value);

			auto it = a_cards.find(value);

			if(it != a_cards.end()) 
			{
				intersection_cards.insert(value);
			}

		}
		int size_a = a_cards.size() - intersection_cards.size(); 


		int size_b = b_cards.size() - intersection_cards.size(); 

		printf("%d\n", (size_a < size_b)? size_a : size_b ) ;

		scanf("%d %d",&A,&B);

	}while(A != 0 && B != 0);

	return 0; 
}
