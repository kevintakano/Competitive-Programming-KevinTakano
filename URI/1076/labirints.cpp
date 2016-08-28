/*
Olá pessoas, 

# A questão disse que o grafo apresentado será semre entre 3 e 7. Ou seja, a matriz para representar o grafo de VERTICES X VERTICES será no máximo 49. 
# O que ele quer é que o carinha faça um caminho onde passe em todos os vértices. Isso é nada mais que um caminho em DFS considerando o caminho que ele percorre tanto para as cores pretas quanto para as cinzas.
# Para entender melhor é só tirar o comentário dos printfs no dfs.

*/
#include <stdio.h>
#include <cstdlib>

#define MAX 50

#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX][MAX];
int color[MAX];
int length_path;

void dfs(int v, int nvertex)
{
 	int i;
 	//printf("Vertice atual cinza: %d\n",v);
	color[v]= GRAY;
	int a;
 	for(i=0;i<nvertex;i++)
 		if(graph[v][i] && color[i] == WHITE)
  		{
  			//printf("Verticei visitando %d\n",i);
  			length_path++;
   			dfs(i,nvertex);
  		}
  	color[v] = BLACK;
  	length_path++;
  	//printf("Voltando no vertice %d\n",v);
}

void initialize_graph()
{
	length_path = 0;
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX	 ; j++)
		{
			graph[i][j] = 0;
		}
		color[i] = WHITE;
		//predecessors[i] = -1;
	}
}

void print_vector(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("[%d]",v[i]);
	}
	printf("\n");
}

void print_graph(int nvertex)
{
	for(int i = 0; i < nvertex; i++)
	{
		for(int j = 0; j < nvertex	 ; j++)
		{
			printf("[%d]",graph[i][j]);
		}
		printf("\n");
	}
}

void print_matrix_normal(int N)
{
	printf("----------------NORMAL---------------------\n");
	printf("   ");
	for(int i = 0; i < N;i++) printf("(%d)",i);
	printf("\n");
	for(int i = 0; i < N;i++)
	{
		printf("(%d)",i);
		for(int j = 0; j < N; j++)
		{			
			printf("[%d]",graph[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int case_tests;
	int initial_vertex;
	int nvertex, ndges; 
	scanf("%d",&case_tests);
	for(int current_test = 0; current_test < case_tests; current_test++)
	{
		initialize_graph();
		scanf("%d",&initial_vertex);
		scanf("%d %d",&nvertex,&ndges);
		for(int current_edge = 0; current_edge < ndges; current_edge++)
		{
			int v1,v2;
			scanf("%d %d",&v1,&v2)	;
			graph[v1][v2] = 1; 
			graph[v2][v1] = 1; 

		}
		dfs(initial_vertex,nvertex);
		printf("%d\n",length_path-1);
	}
	return 0;
}