#include <bits/stdc++.h>

#define MAX 100004
using namespace std;

int numbers[MAX];
int pd[100][MAX];

void print(int N,int L) {
    for(int i = 0; i < N;i++) {
        for(int j = 0; j < L;j++) {
            printf("[%d]",pd[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N,L;

    while(cin >> N >> L and N and L) {
        for(int i=0;i<L;i++)
            memset(pd[i],0,N*sizeof(int));

        for(int i = 0; i < L;i++) {
            cin >> numbers[i];
        }

        for(int i = 0; i + N < L + 1;i++) {
            for(int j = i+1; j < N+i+1;j++) {
                int min = i;
                int max = i;
                for(int k = i; k < j;k++){
                    if( numbers[k] < numbers[min] ){
                        min = k;
                    }
                    if( numbers[k] > numbers[max] ){
                        max = k;
                    }
                }
                int n = j-i;
                pd[i][j-i-1] = ((numbers[max] - numbers[min] + 1)) - n;
                printf("numbers[max] (%d) - numbers[min] (%d) , (n)(%d) , pd[i(%d)][j(%d)-i(%d)-1=%d]=%d \n",numbers[max],numbers[min],n,i,j,i,j-i-1,pd[i][j-i-1]);

            }

            print(2,N);
        }

    }

}
