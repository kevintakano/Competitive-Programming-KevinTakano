#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int N;

    int V[101];
    V[0] = 0;
    for(int i = 1;i <= 100;i++)
    {
        V[i] = i*i + V[i-1];
    }

    while(cin >> N && N)
    {
        printf("%d\n",V[N]);
    }

    return 0;
}