#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;

     cin >> N;

    int c;
    int minor = 99999;
    int min_pos = 0;
    for(int i = 1;i<= N;i++) {
        cin >> c;

        if( c < minor ) {
            minor = c;
            min_pos = i;
        }
    }


    cout << min_pos << endl;
}
