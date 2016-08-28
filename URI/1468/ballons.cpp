#include <bits/stdc++.h>
#define MAX 10*10*10*10*10

using namespace std;

typedef struct 
{
	int x1,y1;
	int x2,y2;	
} roof;

roof roof_vector[MAX];

int pega_maior(roof a)
{
	if(a.y1 > a.y2)
		return a.y1; 
	else return a.y2;
}

int compara(roof a, roof b)
{
	int maior_a = pega_maior(a); 
	int maior_b = pega_maior(b);
	return maior_a < maior_b;
}

int main()
{
	int n,c;
	
	while(scanf("%d %d",&n,&c) != EOF)
	{
		int x1,y1;
		int x2,y2;

		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			roof_vector[i].x1 = x1; roof_vector[i].y1 = y1; 
			roof_vector[i].x2 = x2; roof_vector[i].y2 = y2;
		}

		sort(roof_vector, roof_vector + n, compara);

		/*for(int i = 0; i < n; i++)
		{
			printf("[%d]", pega_maior( roof_vector[i] ));
		}*/

		int saiu = 0;

		int xb, yb = 0;
		int i,j;
		for( i = 0; i < c; i++)
		{
			scanf("%d",&xb);
			//printf("balão lido %d\n",xb);
			for( j = 0; j < n; j++)
			{
				//printf("telhados xs lidos %d %d\n",roof_vector[j].x1,roof_vector[j].x2);

				if(roof_vector[j].x1 <= xb && xb <= roof_vector[j].x2  ||  roof_vector[j].x2 <= xb && xb <= roof_vector[j].x1 )
				{
					//printf("balão %d está entre %d %d\n",xb,roof_vector[j].x1,roof_vector[j].x2);
					if( (roof_vector[j].y1 - roof_vector[j].y2) > 0 )				
					{
						xb = roof_vector[j].x1 ; 
						yb = roof_vector[j].y1;
					} 
					if ( ( roof_vector[j].y1  - roof_vector[j].y2 )  < 0 )  // / 
					{
						xb = roof_vector[j].x2; 
						yb = roof_vector[j].y2;
					} 
					if( ( roof_vector[j].y1  - roof_vector[j].y2 )  == 0 )  // / 				
					{
						yb = roof_vector[j].y1;		
						saiu = 1;
						break;

					}	
				}								
				//printf("posição atual balão %d %d\n",xb,yb);

			}
			if(saiu)
				printf("%d %d\n",xb,yb);
			else 
				printf("%d\n",xb);
			saiu = 0;

		}	

	/*	for(int i = 0; i < n; i++)
		{
			roof_vector[i].x1 = roof_vector[i].x2 = roof_vector[i].y1 = roof_vector[i].y2;
		}*/
	}
	
	return 0;


}