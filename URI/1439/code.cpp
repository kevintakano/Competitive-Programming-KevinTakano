#include <bits/stdc++.h>
#include <algorithm> 

using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
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

#define AS 1
#define VALETE 11
#define DAMA 12
#define REI 13
#define HORARIO 1
#define ANTI_HORARIO 0

struct carta
{
    int valor; char naipe;

    void change_naipe()
    {

        if(naipe == 'C') naipe = 1; // paus
        if(naipe == 'D') naipe = 2; // ouros
        if(naipe == 'H') naipe = 3; // copas
        if(naipe == 'S'  ) naipe = 4; // espadas
    }
    bool operator<(const carta &b) const
    {
        return (valor*naipe) > (b.valor*b.naipe)    ;
    }
};

deque<carta> pilha_saque;
deque<carta> pilha_descarte;
multiset<carta> j_mao[11];

bool compativel(carta a, carta b)
{
    return (a.valor == b.valor) || (a.naipe == b.naipe); 
}

int circular(int j, int P)
{
    if(j == P + 1) return 1; 
    if(j == 0) return P; 
    else return j;
}

int prox(int jogador, int direcao, int P)
{
    if(direcao == HORARIO)
    {
        return circular(jogador+1, P);
    } else 
    {
        return circular(jogador-1, P);
    }
}

int main()
{
    int p,m,n;

    while(cin >> p >> m >> n)
    {
        if(p == m && n == p && p == 0) break;

        for0(i,p)
        {
            j_mao[i].clear();
        }

        pilha_saque.clear();
        pilha_descarte.clear();

        int total = 0;

        for1(i,p)
        {
            for0(j,m)
            {
                carta buffer; 
                cin >> buffer.valor >> buffer.naipe;
                buffer.change_naipe();
                j_mao[i].insert(buffer);
                total++;
            }
        }

        carta buffer; 
        cin >> buffer.valor >> buffer.naipe;
        buffer.change_naipe();
        pilha_descarte.push_front(buffer);
        total++;
        for0(i,n - total)
        {
            cin >> buffer.valor >> buffer.naipe;
            buffer.change_naipe();
            printf("i = %d\n",i);
            pilha_saque.push_front(buffer);
        }

        carta topo_descarte = pilha_descarte.front();
        printf("topo atual %d,%d\n",topo_descarte.valor,topo_descarte.naipe);

        int direcao = HORARIO; 
        bool perde_vez = false;
        int vencedor = 0;
        bool fim_de_jogo = false;
        int ant_ativou_especial = false;;

        int j = 1;
        if(topo_descarte.valor == DAMA)
        {
            direcao = !direcao;
        }
        if(topo_descarte.valor == 7)
        {
            forab(i,1,2)
            {
                j_mao[j].insert(pilha_saque.front());
                pilha_saque.pop_front();
            }
            perde_vez = true;
        }
        if(topo_descarte.valor == 1)
        {
            j_mao[j].insert(pilha_saque.front());
            pilha_saque.pop_front();
            perde_vez = true;
        }
        if(topo_descarte.valor == VALETE)
        {
            printf("to nesse if\n");
            perde_vez = true;
        } 
        if(j_mao[j].size() == 0) 
        {
            vencedor = j; fim_de_jogo = true;
        }
        if(!perde_vez)
        {
            bool encontrou = false;
            for(auto carta = j_mao[j].begin(); carta != j_mao[j].end() && encontrou == false;carta++)
            {
                if(compativel(*carta,pilha_descarte.front()))
                {
                    HEY
                    pilha_descarte.push_front(*carta); 
                    j_mao[j].erase(*carta); 
                    encontrou = true;
                    printf("Jogador %d jogou carta %d,%d\n",j,carta->valor,carta->naipe);
                }
            }
             if(j_mao[j].size() == 0) 
            {
                vencedor = j; fim_de_jogo = true;
            }

            if(!encontrou)
            {
                j_mao[j].insert(pilha_saque.front());
                pilha_saque.pop_front();
            }
        }
        perde_vez = false; 

        j = prox(j,direcao,p);

        while(true && fim_de_jogo == false && pilha_saque.size() != 0)
        {
            topo_descarte = pilha_descarte.front();
            printf("topo atual %d,%d\n",topo_descarte.valor,topo_descarte.naipe);
            printf("jogador atual %d\n",j);

            if(topo_descarte.valor == DAMA && !ant_ativou_especial) ant_ativou_especial = true;
            if(topo_descarte.valor == DAMA && ant_ativou_especial)
            {
                printf("if 1\n");
                direcao = !direcao;
                ant_ativou_especial = false;
            }

            if(topo_descarte.valor == 7 && !ant_ativou_especial) ant_ativou_especial = true;
            if(topo_descarte.valor == 7 && ant_ativou_especial)
            {
                printf("if 2\n");
                printf("Entrei aqui em 7\n");
                for(int i = 1; i <= 2 && pilha_saque.size() != 0;i++)
                {
                    printf("Inserindo na mao de j = %d a carta %d,%d\n",j,pilha_saque.front().valor,pilha_saque.front().naipe);
                    j_mao[j].insert(pilha_saque.front());
                    pilha_saque.pop_front();
                }
                ant_ativou_especial = false;
                perde_vez = true;
            }
            if(topo_descarte.valor == 1  && !ant_ativou_especial) ant_ativou_especial = true;
            if(topo_descarte.valor == 1  && ant_ativou_especial)
            {
                printf("if 3\n");
                j_mao[j].insert(pilha_saque.front());
                pilha_saque.pop_front();
                ant_ativou_especial = false;
                perde_vez = true;
            }
            if(topo_descarte.valor == VALETE &&  !ant_ativou_especial)  ant_ativou_especial = true;
            if(topo_descarte.valor == VALETE &&  ant_ativou_especial)
            {
                printf("if 4\n");
                ant_ativou_especial = false;
                perde_vez = true;
            }
            if(j_mao[j].size() == 0) {
                vencedor = j; 
                fim_de_jogo = true;
            }

            if(!perde_vez)
            {
                bool encontrou = false;

                for(auto carta = j_mao[j].begin(); carta != j_mao[j].end() && encontrou == false;carta++)
                {
                     printf("   carta = %d,%d e carta_descarte %d,%d\n",carta->valor,carta->naipe,pilha_descarte.front().valor,pilha_descarte.front().naipe);
                    if(compativel(*carta,pilha_descarte.front()))
                    {

                        printf("Jogador %d jogou carta %d,%d\n",j,carta->valor,carta->naipe);
                        pilha_descarte.push_front(*carta); 
                        j_mao[j].erase(*carta); 
                        encontrou = true;
                    }
                }
                if(j_mao[j].size() == 0) {
                    vencedor = j; 
                    fim_de_jogo = true;
                }

                if(!encontrou)
                {
                    j_mao[j].insert(pilha_saque.front());
                    pilha_saque.pop_front();
                }
            }
            perde_vez = false; 

            j = prox(j,direcao,p);
            HEYB
        }   
        printf("%d %d %d\n",p,m,n);
        printf("%d\n",vencedor);
    }
}