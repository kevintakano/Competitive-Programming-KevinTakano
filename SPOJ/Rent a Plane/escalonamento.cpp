#include <bits/stdc++.h>
#define oi printf("oi");
#define oi2 printf("oi2");
#define oi3 printf("oi3");
#define oi4 printf("oi4");
#define oi5 printf("oi5");
#define oi6 printf("oi6");
#define endline printf("\n");
#define MAX 10000
/*

	p(j) -- retorna a ultima tarefa i , tal que i < j que não tem tempo de duração que conflite com j;
	opt j = if(j  == 0) return 0 else max(value(j) + opt(p(j), opt(j-1)) 
		
*/
using namespace std;
typedef struct b
{
	int start;
	int duration; 
	int price; 
} Order; 

Order *orders; 
//int p[MAX] ;
int *opt; 

void print_vector(int v[], int n);

/*void compute_p( int n)
{
	int i = 1; 
	while(i <= n) // vai até 1
	{
		for(int j = 1; j <= n ; j++)
		{
			//printf(" (%d , %d) %d : %d\n",j,i,orders[i - j].duration + orders[i-j].start , orders[i].start  );
			if(  (orders[j].duration + orders[j].start)  <  orders[i].start  && j != i)
			{
				printf(" (%d , %d) %d : %d\n",j,i,orders[j].duration + orders[j].start , orders[i].start  );
				if(orders[j].duration > orders[p[i]].duration)
				{
					p[i] = j;
				}
			}	
		}
		i++;
		

	}		
		
}
*/
int get_p(int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (orders[j].duration + orders[j].start <= orders[i].start)
            return j;
    }
    return -1;
}

int max(int a, int b)
{
	return a > b ? a : b; 
}
void print_vector(int v[], int n)
{	
	for(int i = 0; i<= n; i++ )
	{
		printf("[%d]",v[i]);
	}
	endline
}

bool compare(Order a, Order b)
{
	return (a.duration + a.start) < ( b.duration + b.start );
}

int find_opt(int n) // programaçao dinamica
{

		sort(orders, orders+n+1, compare); 
		
		opt[0] = orders[0].price; // caso base
		for(int j = 1; j <= n; j++)
		{

			opt[j] = max(orders[j].price + opt[get_p(j)], opt[j-1]);
		}
		return opt[n];
}

void clear_orders(int n)
{
	int i = 0; 
	while(i <= n)
	{
		orders[i].duration = 0;
		orders[i].start = 0;
		orders[i].price = 0;
		i++;
	}
}

int main()
{
	int number_test_case, number_of_orders;
	orders = (Order*)malloc(sizeof(Order) * MAX);
	opt = (int*)malloc(sizeof(int) * MAX);

	int test_case;
	scanf("%d",&number_test_case);
	 
	test_case = 0;	
	while(test_case < number_test_case)
	{
		scanf("%d",&number_of_orders);
		clear_orders(number_of_orders); 	
		for(int k = 0; k <= number_of_orders;k++) // clear p 
		{			
			opt[k] = 0;
		}	

		int i = 0; 
		
		while(i < number_of_orders)
		{
			scanf("%d %d %d",&orders[i+1].start,&orders[i+1].duration,&orders[i+1].price); 				
			i++;
		}
		test_case++;
		//compute_p(number_of_orders);
		printf("%d\n",find_opt(number_of_orders));
		//print_vector(opt,number_of_orders);

		// clear_vector
		//test_case += 1;
	}


	return 0;
}
