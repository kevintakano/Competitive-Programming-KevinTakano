//RNA
// Kevin Takano
#include <cstdio>
#include <list>
#include <cstring> 

using namespace std; 

typedef struct no
{

	char ch ;
	struct no *esq;
	struct no *dir;

}tipoNo;


void insert(tipoNo *p, tipoNo *p2, char ch)
{
	tipoNo *aux = (char*)malloc(sizeof(char));
	aux->dir = ch;
	aux->esq = aux->dir = NULL; 

	if(p->esq == NULL && p->dir == NULL)
	{
		p = aux; 

		p2 = aux; 
	}
	else 
	{
		p2 = aux; 
		p2->esq = p; 
		p2->dir = NULL;

		
	}
}  


int main()
{
	char string[300];

	while(scanf("%s",string) == 1)
	{
		

	}


	return 0; 
}