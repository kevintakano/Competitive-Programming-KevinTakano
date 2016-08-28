#include <stdio.h>
#include <math.h> // necessário para raiz
 
#define NMAX 1000000 // valor máximo para o valor máximo
 
int main() {
    int i, j, vetor[NMAX];
    int valorMaximo, raiz;
 
    // Primeiro passo
    scanf("%d", &valorMaximo);
 
    // Segundo passo
    raiz=sqrt(valorMaximo);
 
    // Terceiro passo
    for (i=2; i<=valorMaximo; i++) {
        vetor[i]=i;
    }
 
    // Quarto passo
    for (i=2; i<=raiz; i++) {
        if (vetor[i]==i) {
            for (j=i+i; j<=valorMaximo; j+=i) {
                vetor[j]=0; // removendo da lista
            }
        }
    }


    printf("Primos!\n");

    for(int k = 0; k <= valorMaximo; k++){
        if(vetor[k])
            printf("[%d]",vetor[k]);
    } 

    printf("\n"); 

    return 0;
}