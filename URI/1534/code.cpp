#include <bits/stdc++.h>

using namespace std;


int main() {

    int N;

    while(cin >> N){
        for(int i = 0;i < N;i++) {
            for(int j = 0;j< N;j++) {
                int v = 3;
                if( i == j )
                    v = 1;
                if( i + j == N - 1 )
                    v = 2;
                printf("%d",v);
            }
            printf("\n");
        }


    }

}
