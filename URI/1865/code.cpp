#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;

     cin >> N;

     string name;
     for(int i =0;i<N;i++) {
         int K;
        cin >> name >> K;

        if(name == string("Thor")) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
     }
}
