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

struct tarefa
{
    int valor, tempo;

    tarefa()
    {

    }
    tarefa(int v, int t)
    {
        valor = v; tempo = t;
    }


};

bool operator<(const tarefa &t, const tarefa &t2)
{        
    return (t.valor != t2.valor) ? t.valor < t2.valor : t.tempo < t2.tempo;
}

priority_queue<tarefa> tarefas;
vector<tarefa> vtarefas;

int main()
{
    int N,H;
    

    while(cin >> N >> H)
    {
        int v,t;

        tarefas = priority_queue<tarefa>();
        vtarefas.clear();
        int lucro = 0;

        for0(i,N)
        {
            cin >> v >> t;
            lucro += v;
            tarefas.push(tarefa(v,t));
            
        }
        int tempo = 1;
        int lucro_acum = 0;
        int valorant_igual = 0;
        bool tem_igual = false;

        while(!tarefas.empty() && tempo <= H)
        {
            tarefa t = tarefas.top(); tarefas.pop();
            vtarefas.push_back(t);
            if(valorant_igual == t.tempo) tem_igual = true;
            printf("(%d,%d)\n",t.valor,t.tempo);
            printf("tempo %d e t.tempo %d\n",tempo,t.tempo);
            lucro_acum += t.valor;
            if(tempo > t.tempo)
            {
                break;
            }
            valorant_igual = t.tempo;
            tempo++;
        }
        tempo = 1;

        if(tem_igual)
        {
            printf("TEM IGUAL!\n");
            sort(vtarefas.begin(),vtarefas.end(),[]
            (tarefa &a, tarefa &b)
            {
                return a.valor > b.valor;
            });

            auto ant = vtarefas.begin();
            for(auto rit = vtarefas.begin(); rit != vtarefas.end();rit++)
            {
                printf("rit->valor %d e rit->tempo %d\n",rit->valor,rit->tempo);
                if(tempo > rit->tempo)
                {
                    printf("removi rit-> valor %d\n",rit->valor);
                    lucro_acum -= rit->valor;
                }            
                ant = rit;
                tempo++;
            }
        }

        printf("%d\n",lucro - lucro_acum);
    }



}