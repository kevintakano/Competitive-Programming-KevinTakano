#include <bits/stdc++.h>
#include <algorithm> 

using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)

#define pm(mat,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mat[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

typedef long long int ll;

int h[10003];


int main()
{
    int N;


    while(cin >> N && N)
    {
        for0(i,N)
        {
            cin >> h[i];
        }




        int peaks = 0;
        int state = -1;
        int ant = -1;

        h[N] = h[0];    
        h[N+1] = h[1];

        // pa(h,N+2);
        int i = 0;
        while(i <= (N))
        {
            ant = state; 
            if(h[i] > h[i+1]) state = 0; // descendo
             else 
            state = 1; //subiu;
            if(i == 0) ant = state;
            if(state != ant)
            {
                // printf("Estados diferentes em i = %d\n",i);
                peaks++;
            }
            i ++;
        }

        printf("%d\n",peaks);

    }

    return 0;
}