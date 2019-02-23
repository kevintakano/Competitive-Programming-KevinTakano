#include<bits/stdc++.h>
#define MAX 50001
using namespace std;

int vet[MAX];
int index_map[MAX];

void apply_reverse(int vet[], int a, int b){
    while(b > a){
        swap(vet[a], vet[b]);
        swap(index_map[vet[a]],index_map[vet[b]]);
        a++;
        b--;
    }
    return;
}

int main(){
    int n, cont = 0;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            vet[i] = i;
            index_map[i] = i;
        }
        int r;
        scanf("%d",&r);
        for(int i = 0;i < r;i++) {
            int a, b;
            scanf("%d%d",&a,&b);
            apply_reverse(vet,a,b);
        }
        int Q;
        scanf("%d",&Q);
        printf("Genome %d\n",cont+1);
        for(int i=0;i<Q;i++) {
            int ind;
            scanf("%d",&ind);
            printf("%d\n",index_map[ind]);
        }
        cont++;
    }
    return 0;
}

