#include <cstdio>
 #include <cstring>

#define LMAX 21
#define CMAX 31
#define max(a, b) a > b ? a : b
 
struct Pedido{
    int tempo;
    int pizzas;
};
 
struct Pedido array[LMAX];
int matriz[LMAX][CMAX];
 
int main()
{
    int N, P;
 
    while(scanf("%d", &N) && N){
        scanf("%d", &P);
        for(int i = 1; i <= N; i++)
            scanf("%d %d", &array[i].tempo, &array[i].pizzas);
        // memset(matriz,0,sizeof matriz);
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= P; j++){
               
                    if(array[i].pizzas > j)
                        matriz[i][j] = matriz[i - 1][j];
                    else
                        matriz[i][j] = max(matriz[i - 1][j - array[i].pizzas] + array[i].tempo, matriz[i - 1][j]);
                
            }
        }
 
        printf("%d min.\n", matriz[N][P]);
    }
 
    return 0;
}