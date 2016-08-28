#include <cstdio> 
#include <list>

// For n = 17 and m =  5 [0, 5, 10, 15, 4, 11, 1, 8, 16, 9, 3, 14, 13, 2, 7, 12, 6]


using namespace std;

int interval_contain_removed(int init, int end, list<int> &removeds, int n)
{
	int total_passeds_removeds = 0;

	for(auto & obj : removeds)
	{
		if(init < obj && obj < end)
		{
			printf("1\n");
			printf("	obj %d\n",obj);
			total_passeds_removeds++;
		}
		else if(end < init)
		{
			if((init < obj && obj <= (n-1)) || (0 <= obj && obj < end))
			{
				printf("2\n");
				printf("	obj %d\n",obj);
				total_passeds_removeds++;
			}
		}
	}
	return total_passeds_removeds;
}

void print_list(list<int> ls)
{
	for(auto &obj : ls)
	{
		printf("[%d]->",obj);
	}
	printf("\n");
}

int get_minor_m(int n)
{
	int m = 5;

	/*List criation*/

	list<int> ls_regions; 

	for(int i = 0; i < n; i++)
	{
		ls_regions.push_back(i);		
	}

	while(m <= 5)
	{
		list<int> cpy_ls_regions (ls_regions); 
		list<int> removeds_regions; 


		int jump = 0;

		int init = 0;

		for(int i = 0; i < n - 1; i++)
		{	

			int nex_pos = (jump % (n)); // proxima posição baseada nas voltas

			printf("Next position %d\n",nex_pos); 

			printf("Init %d and End %d\n",init ,nex_pos); 
			getchar();

			int total_passeds_removeds = interval_contain_removed(init,nex_pos,removeds_regions,n);

			printf("		nex_pos 1: %d\n",nex_pos);
			nex_pos += total_passeds_removeds;  // incrementa 
			printf("		nex_pos 2: %d\n",nex_pos);
			nex_pos = (nex_pos % (n));  // faz uma rotação, pois é possível que a incrementação passe o tamanho n
			printf("	Next position %d\n",nex_pos);


			printf("Posição removida %d\n",nex_pos);
			removeds_regions.push_back(nex_pos);
			cpy_ls_regions.remove( nex_pos );

			printf("Removed regions : : ");
			print_list(removeds_regions);

			init = nex_pos; 
			printf("Before jump %d\n",jump);
			jump += total_passeds_removeds; 
			jump += m; 
			printf("Next jump %d\n",jump);
		}

		int last_elem = cpy_ls_regions.front();

		if(last_elem == 12)
		{
			return m; 
		}

		m++; 
	}	

	return 0;
}

int main()
{

	int read;

	do
	{
		scanf("%d",&read); 
		if(read == 0)
		{
			break;
		}
		int m = get_minor_m(read);

		printf("%d\n",m); 

	}while(read != 0);

	return 0;
}