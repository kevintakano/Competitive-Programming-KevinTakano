#include <bits/stdc++.h>

using namespace std;


int isT(int a, int b, int c) {

    bool c3 = abs(b - c) < a and a < (b + c);
    bool c2 = abs(a - c) < b and b < (a + c);
    bool c1 = abs(a - b) < c and c < (a + b);

    //printf("%d %d %d\n",b-c,a,b+c);
    //printf("%d %d %d\n",a-c,b,a+c);
    //printf("%d %d %d\n",a-b,c,a+b);

    return c1 == true and c2 == true and c3 == true;
}

int main() {

    int A,B,C,D;

    int vec[4];

    cin >> A >> B >> C >> D;

    vec[0] = A;
    vec[1] = B;
    vec[2] = C;
    vec[3] = D;


    bool isTriangle = false;

    for(int i = 0;i < 4;i++) {
        for(int j = i + 1;j < 4;j++) {
            for(int k =  j + 1;k < 4;k++) {
                int a = vec[i];
                int b = vec[j];
                int c = vec[k];

                if(isT(a,b,c)) {
                    isTriangle = true;
                    //printf("%d %d %d",a,b,c);
                    //printf("%d %d %d",i,j,k);
                    goto final;
                }
            }
        }
    }

final:
    cout << (isTriangle  == true? "S" : "N") << endl;
  }
