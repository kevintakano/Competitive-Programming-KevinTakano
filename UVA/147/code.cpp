#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int lld;

lld COINS[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
lld AMOUNT;
double AMOUNT_D;
lld COMB[30000 + 1][12];

lld solve() {

    for(int c = 0;c <= 11;c++) COMB[0][c] = 1;

    for(int v = 1;v <= AMOUNT;v++) {
        for(int c = 1; c <= 11;c++) {
            if( v >= COINS[c-1] ) {
                COMB[v][c] = COMB[v-COINS[c-1]][c] + COMB[v][c-1];
            } else {
                COMB[v][c] = COMB[v][c-1];
            }
        }
    }

    return COMB[AMOUNT][11];
}

void print() {
    for(int v = 0; v <= AMOUNT;v++) {
        for(int c = 0; c <= 11; c++) {
            printf("[%lld]",COMB[v][c]);
        }
        printf("\n");
    }
}



int main() {
    while(cin >> AMOUNT_D) {
        AMOUNT = (lld) round(AMOUNT_D*100);
        if (AMOUNT == 0) break;

        printf("%6.2f%17lld\n",AMOUNT_D,solve());
        //print();
    }

}

