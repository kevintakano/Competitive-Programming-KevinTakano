#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
 
#define pm(mat,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mat[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

#define MAX 10000


vector<string> ativos;
int baralho[53];
struct tipoJogada {
int v; string j;

tipoJogada(int pv, string pj)
{
	v = pv; j = pj;
}

tipoJogada()
{

}

};



int main()
{
	int N;
	while(cin >> N && N)
	{
		ativos.clear();
		for0(i,N){ string  buffer; cin >> buffer; ativos.push_back(buffer);}

		for0(i,52)
		{
			cin >> baralho[i];
		}
		int cartas_pegas = 0;
		bool venceu = false;
		int n_jogadores = N;
		int jogadas = 0;
		while(cartas_pegas < 52 && !venceu)
		{

			tipoJogada buf[ativos.size()];
		
			for0(i,ativos.size()) // Distribui as cartas
			{			
				buf[i] = tipoJogada(baralho[cartas_pegas],ativos[i]);
				cartas_pegas++;
				
				
			}	
			if(cartas_pegas > 52) break; // se ultrapassar, deu empate e imprime a galera :D

			sort(buf,buf + ativos.size(),[](tipoJogada a, tipoJogada b){return a.v < b.v;});
			
			int ant = 0;
			int i = 1;
			
			list<string> remover;
			bool tudo_igual = true;
			
			/*printf("buf = ");
			for(int i = 0; i < ativos.size();i++)
				printf("[%d]",buf[i].v);
			printf("\n");
			*/
			while(i < ativos.size()) // Verifica se em um turno, todos os integrantes tem valores iguais
			{
				if(buf[ant].v != buf[i].v) {tudo_igual = false;break;}
				ant = i;
				i++;
			}
			i = 0, ant = 0;
			
			if(tudo_igual == false)
			{
				while(buf[i].v == buf[ant].v) // insere em uma estrutura de dados (uma lista simples) para ter os menores elementos iguais
				{
					//cout << "Inserindo no remover " << buf[i].v << " com  string " << buf[i].j << endl;
					remover.push_back(buf[i].j);
					ant = i;
					i++;
				}		
			
										
				for(auto it = ativos.begin(); it != ativos.end();)
				{
					auto it2 = find(remover.begin(),remover.end(),*it); // se encontrar o valor *it na estrutura remover, então remove it do vetor
					if(it2 != remover.end()) 
					{
						//cout << "Estou removendo " << *it << END;	
						it = ativos.erase(it);
					} else it++; 
				
					if(ativos.size() == 1) // se depois da remoção o total de jogadores for 1 então o jogo acabou!
					{
						venceu = true; break;
					}
				}		
			
			}else break;
		}
		
		for(auto it = ativos.begin(); it != ativos.end();it++)
		{			
			cout << *it << " ";			
		}	
		cout << END; 

	}
}









