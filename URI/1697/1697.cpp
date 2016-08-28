#include <cstdio>
#include <algorithm>
#include <set> 

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("Hey i'm here!\n");



int main()
{
	int T;

	scanf("%d",&T);


	for(int i = 0; i < T;i++)
	{
		set<int> result; 

		int N; 

		scanf("%d",&N);
		int LIST[MAX];
		int tam = 0;

		int found_1 = 0 ;

		for(int j = 0; j < N;j++)
		{
			int a;
			scanf("%d",&a);
			if(a == 0)
				continue; 
			result.insert(a);
			LIST[tam] = a; 
			tam++;

			if(a == 1)
			{
				found_1 = 1;
			}
		}

		if(!found_1)
		{
			printf("0\n");

			continue;
		}

		if(tam == 1)
		{
			printf("%d\n",LIST[0]);
			continue;
		}


		for(int k = 0; k < tam; k++)
		{
			for(int l = k + 1; l < tam; l++)
			{
				int multiplicated_value = LIST[k]*LIST[l]; 
				// printf("valor multiplicado inserido %d\n",multiplicated_value);

				result.insert(multiplicated_value);
			}
		}

		// sort(LIST, LIST + new_tam,myfunction);

		int value = 1;

		int X = 0;

	
		int last_obj = *result.begin();

		for(auto &obj : result)
		{
			if(obj != value)
			{
				// printf("Diferente quando value = %d e obj = %d\n",value,obj);
				X = last_obj; // last obj is X, because it's the greate than all;
				break;
			}
	
			
			last_obj = obj;

			value++;
		}

		if(found_1 == 1){
			printf("%d\n",X);
		}
		else 
			printf("0\n");

	}	



	return 0;
}