#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
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


const int MAX = 600;
int grade[100][100];

char s1[MAX],s2[MAX];
int mat[MAX][MAX];

bool validoY(int y, int N, int M)
{
    return y >= 0 && y < N;
}

bool validoX(int x, int N, int M)
{
    return x >= 0 && x < M;
}
int main()
{
    int T;

    cin >> T;
    int inst = 1;
    while(T--)
    {

        int H,W;
        memset(mat,0,sizeof mat);
        memset(s1,0,sizeof s1);
        memset(s2,0,sizeof s2);
        cin >> H >> W;
        
        string s;

        for0(i,H)
        {
            cin >> s;
            for0(j,W)
            {
                grade[i][j] = s[j];
            }
        }

        int N,X,Y; cin >> N >> X >> Y;
        int N1 = N;
        X--,Y--;
        
        if(N1 != 0) cin >> s;

        s1[0] = grade[X][Y];

        for0(i,N)
        {
            char c = s[i];
            // printf("c=  %c\n",c);   
            if(c == 'E')
            {
                Y++;
            }
            if(c == 'L')
            {
                Y--;
            }
            if(c == 'S')
            {
                X++; 
            }
            if(c == 'N')
            {
                X--;
            }

            // if(validoY(Y,H,W))
            // {
                s1[i+1] = grade[X][Y];                                    
            // } 
        }

        s1[N1+1] = '\0';

        // printf("s1 = %s\n",s1);

        cin >> N >> X >> Y;
        int N2 = N;
        X--,Y--;
        
        s.clear();

        if(N2 != 0)cin >> s;

        s2[0] = grade[X][Y];

        for0(i,N)
        {
            char c = s[i];
            // printf("c=  %c\n",c);   
            if(c == 'E')
            {
                Y++;
            }
            if(c == 'L')
            {
                Y--;
            }
            if(c == 'S')
            {
                X++; 
            }
            if(c == 'N')
            {
                X--;
            }

            // if(validoX(X,H,W))
            // {
                s2[i+1] = grade[X][Y];                                    
            // }  // N2--;
        }

        s2[N2+1] = '\0';

        int res = 0;
        N1++,N2++;
        
        // printf("s1 %s s2 %s\n",s1,s2);
        // printf("N1 %d e N2 %d\n",N1,N2);

        /*for(int i = 1;i<=N1;i++)
        {
            if(s1[0]==s2[i-1])    
                printf("oi\n"),mat[i][0] = mat[i-1][0] + 1;
            else 
                mat[i][0] = mat[i-1][0] ;
        }
        for(int i = 1;i<=N2;i++)
        {
            if(s1[i-1]==s2[i-1])
                mat[0][i] = mat[0][i-1] + 1;
            else
                mat[0][i] = mat[0][i-1];
        }*/

        for(int i = 1;i <= N1;i++)
        {
            for(int j = 1;j <= N2;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    //printf("entrei !\n");
                    mat[i][j] = mat[i-1][j-1] + 1, res=max(res,mat[i-1][j-1]+1);
                    //printf("res = %d\n",res);
                }
                else mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
            }
        }

        /*for0(i,N1+1)
        {
            for0(j,N2+1)
            {
                printf("[%d]",mat[i][j]);
            }
            ENDLINE
        }*/

        // printf("res = %d\n",res);
        printf("Case %d: %d %d\n",inst,(N1-mat[N1][N2]),( N2 - mat[N1][N2] ) );
        inst++;
    }

}