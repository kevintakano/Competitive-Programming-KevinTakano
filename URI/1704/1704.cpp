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

vector<tarefa> tarefas;
vector<bool> tarefas_adicionadas(1005);

int main()
{
    int N,H;

    while(cin >> N >> H)
    {
           // cout << "*********8\n";
        int lucro_total = 0;
        tarefas.clear();

        int executa_crescente = true;   
        //fill(tarefas_adicionadas.begin(),tarefas_adicionadas.end(),false);
        for0(i,N) 
        {
            int a,b; cin >> a >> b; 

            

            lucro_total  += a;
            tarefas.push_back(tarefa(a,b));
            tarefas_adicionadas[b] = true;
        }

/*
        if(executa_crescente)
        {
            sort(tarefas.begin(),tarefas.end(),[](const tarefa &a,const tarefa &b){if(a.valor != b.valor) return a.valor < b.valor; else return a.tempo < b.tempo; });

        }
        else{
        }*/

            sort(tarefas.begin(),tarefas.end(),[](const tarefa &a,const tarefa &b){if(a.valor != b.valor) return a.valor > b.valor; else return a.tempo > b.tempo; });
        for0(i,N)
        {
            printf("[%d,%d]",tarefas[i].valor,tarefas[i].tempo);
        }
        ENDLINE

        int i = 0;
        int tacumulado = 0;
        int vacumulado = 0;
        int tempo = 0;

        while( N-- && tempo <= tarefas[i].tempo)
        { 
            vacumulado += tarefas[i].valor;

            tacumulado += tarefas[i].tempo;
            // printf("Acumulei %d\n",tarefas[i].valor );
            i++;
            tempo++; 
        }

        // i--;
        // vacumulado -= tarefas[i].valor; 
                
        // printf("vacumulado %d **\n",vacumulado);
        // printf("%d **\n",lucro_total);

        printf("%d\n",lucro_total - vacumulado);
    }

}