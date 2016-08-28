#include <stdio.h> 
#include <string.h> 

#define MAX_PEOPLE (10000+1)
#define VIVO 0
#define MORTO 1
#define ENDLINE printf("\n");

//int STATUS_PEOPLE[MAX_PEOPLE];

/*
void print_status_people(int max_people)
{
	int i;
	for(i=1;i<=max_people;i++)
	{
		if(STATUS_PEOPLE[i] == MORTO)
		{
			printf("[MORTO]");
		} else 
		{
			printf("[VIVO]");
		}
	}
	printf("\n");
}
*/
int rotation_in_josephus(int index, int max_people)
{
	return (index % max_people == 0) ? max_people : index % max_people; 
}

int next_element_alive_circular_list(int status_people[], int init, int max_people, int jump)
{
	int count_jump = 1; 
	int delta = 0;
	int next_verify = init + count_jump;
	int killeds = 0;	

	// printf("		Vetor atual quando init e igual %d: ",init); 
	// printf("		");
	// print_status_people(max_people);
	
	// printf("		Primeiro a verificar %d\n",next_verify);
	while(count_jump <= jump )
	{
		next_verify = rotation_in_josephus(next_verify,max_people);
		// printf("			Estou verificando %d\n",next_verify);
		if(status_people[next_verify] == MORTO)
		{
			// printf("			next_verify %d está morto!\n",next_verify);
			//next_verify++;  // número de mortos
			count_jump--;
			killeds++; 
		}
		count_jump++;
		next_verify++; 
		//printf("	contando \n");
	}
	next_verify--;
	int final_jump = init + jump + killeds; 	

	// printf("		Pulo final %d e proximo a verificar %d\n",final_jump,next_verify);
	// printf("		Índice final de pulo %d\n",rotation_in_josephus(final_jump,max_people));
	return rotation_in_josephus(final_jump,max_people);
}	


int recursive_solution(int n , int k)
{
	if(n == 1)
	{
		return 1;
	}else{

		int next = recursive_solution(n-1,k);

		//printf("	recursive_solution(n-1,k) %d\n",next); 
		//printf("	final value %d\n",(next + k-1)%n + 1); 

		return (next + k-1)% n + 1; 
	} 		
}

/*
*  Explicação da Solução Recursiva
*  O último cara que irá sobreviver ou Josephus 
*  		Será: 
*			O cara que terá id 1 se n == 1
* 			Ou
*           Correcao_para_lista_circular(Correcao_da_chamada(Ultimo_josephus_de_nmenos1_com_mesmo_k) + Salto)) 
*
*			Correcao_da_chamada pega o valor do ultimo josephus e subtrai 1, pois a chamada j(n-1,k) retorna o valor considerando que o josephus começa em 1 e não em n
*			Correcao_para_lista_circular() pega o resultado da soma no parâmetro e pega o resto em relação a n e soma + 1 para não começar em zero.
*/

int main()
{
	

	int NC;
	int jump, max_people; 
	scanf("%d",&NC);
	int test_case = 0; 

	int people_died = 0;
	int element_to_kill = 0;



	while(test_case < NC)
	{
		scanf("%d %d",&max_people,&jump); 
		/*people_died = max_people;
		element_to_kill = people_died;*/ 
		//memset(STATUS_PEOPLE,VIVO,MAX_PEOPLE);
		// while(people_died >= 1)
		// {

		element_to_kill = recursive_solution(max_people,jump);
			//STATUS_PEOPLE[element_to_kill ] = MORTO;
			//printf("element to kill %d\n",element_to_kill);
			// people_died--;
		// }
		/*ENDLINE; 
		printf("                       ");
		print_status_people(max_people);
		ENDLINE; */
		printf("Case %d: %d\n",test_case+1,element_to_kill);
		// ENDLINE; 
		test_case++;
	}
	//ENDLINE
	 return 0;
}