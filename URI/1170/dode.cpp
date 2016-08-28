#include<iostream>
using namespace std;
int main(){
    int N;
    double C,i,x;
    cin >> N;
    x = 0;
    while(N>0){
        cin >> C;
        while(C>1){
            C = C / 2;
            x++;
        }
        cout << x << " dias" << endl;
        N--;
        x = 0;
    }
}