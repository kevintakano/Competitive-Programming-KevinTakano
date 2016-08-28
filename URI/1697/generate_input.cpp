#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{

	srand(time(NULL));

	int k = 0;
	int total = 0;

	int T = 100;

	printf("%d\n",T);


	for(int j = 0; j < T; j++)
	{
		total = 0;

		int delta = rand() % (1000000/100000);

		int max = 1000000/1000000 + delta; 

		printf("%d\n",max);

		k = 0;

		for(int i = 0; total < max; i++)
		{
			if(k < max/2)
			{
				printf("%d ",i);
				total++;

			} else{
				i += rand() % 20;			
				printf("%d ",i);
				total++;
				k = 0;

			}
			k++;
		}
		printf("\n");
	}

	
	//printf("\n");
	//printf("total %d\n",total);
}