
#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define pti(S,I) printf("%s:%d\n",S,I);	

int bissexto(int ano)
{
	if(ano % 400 == 0 && ano % 4 == 0 && ano % 100 != 0) return 1; else return 0;
}

int encontra_dias_bissextos(int ano1, int mes1, int dia1, int ano2, int mes2, int dia2)
{

	int res = 0;

	for(int ano = ano1; ano <= ano2; ano++) // Itera pelos anos, procura dias bissextos, mesmo que no ultimo ano, no dado dia e mes n tenha
	{
		if(bissexto(ano))
		{

			res++;
		}
	}

	if((bissexto(ano2) && mes2 == 2 && dia2 < 29 )|| bissexto(ano2) && mes2 == 1) // 
	{
		res--;
	}

	if(bissexto(ano1) && mes1 > 2) 
	{
		res--;
	}
	return res; 
}


int main()
{
	int N;
	cin >> N;

	int dia_mes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for(int i = 0;i < N;i++)
	{

		int ano1, ano2, mes1,mes2,dia1,dia2;

		int dias = 0;

		scanf("%d-%d-%d %d-%d-%d",&ano1,&mes1,&dia1,&ano2,&mes2,&dia2);
		// printf("Lido: %d-%d-%d %d-%d-%d\n",ano1,mes1,dia1,ano2,mes2,dia2);

		if(ano2 < ano1){
			swap(ano1,ano2);
			swap(mes1,mes2);
			swap(dia1,dia2);		
			HEY 	
		} else 	if(mes2 < mes1 && ano1 == ano2)
		{
			swap(mes1,mes2);
			swap(dia1,dia2);
			HEY2
		}else 
		if(dia2 < dia1 && mes1 == mes2 && ano1 == ano2)
		{
			swap(dia1,dia2);
			HEY3	
		} 


		// printf("Final: %d-%d-%d %d-%d-%d\n",ano1,mes1,dia1,ano2,mes2,dia2);


		dias += (ano2 - ano1) * 366;

		dias += encontra_dias_bissextos(ano1,mes1,dia1,ano2,mes2,dia2);
		
		// pti("dias",dias);

		for(int mes = mes1 + 1; mes < mes2 ; mes++)
		{
			dias += dia_mes[mes];
		}

		// pti("dias",dias);

		if(mes2 != mes1) dias += (dia2 + dia_mes[mes1] - dia1 );else dias += dia2 - dia1;


		cout << dias << END;
	}

	return 0;
}