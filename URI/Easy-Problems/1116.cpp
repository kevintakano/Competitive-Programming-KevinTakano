#include <iostream>
 #include <iomanip> 
#include<cstdio>

using namespace std;
 
int main() {
 
    int N;
    
    double X,Y;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        
        if(Y == 0)
        {
            cout << "divisao impossivel" << endl;
        } else 
        {
            printf("%.1f\n",X/Y);
        }
    }
 
    return 0;
}