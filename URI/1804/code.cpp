#include <bits/stdc++.h>
#define MAX 100100
using namespace std;

int buggy[MAX];
int index_map[MAX];

int main(){


    int n;

    cin >> n;

    for(int i = 1;i <= n;i++) {
        cin >> buggy[i];
        index_map[i] = i;
    }

    int op, abd;

    while(cin >> op >> abd) {
        if(op == 'a') {
            index_map[abd]
        }
        if(op == '?') {

        }
    }

}

