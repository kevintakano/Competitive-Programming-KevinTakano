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

const int MAXN = 1001, INF = 0x3f3f3f3f;;

int main()
{
    int N;
    cin >> N;

    int SUDOKU[9][9]; 

    int rows[9][9+1];
    int cols[9][9+1];
    int blocks[9][9+1];

    for1(k,N)
    {
        memset(rows,0,sizeof rows);
        memset(cols,0,sizeof cols);
        memset(blocks,0,sizeof blocks);

        int flag = 1;

        //

        for0(i,9)
        {
            for0(j,9)
            {
                cin >> SUDOKU[i][j];
                cols[j][SUDOKU[i][j]]++; 
                rows[i][SUDOKU[i][j]]++; 
                blocks[i/3*3 + j/3][SUDOKU[i][j]]++; 

                if(cols[j][SUDOKU[i][j]] > 1)
                {
                    flag = 0;
                }
                if(rows[i][SUDOKU[i][j]] > 1)
                    {
                        flag = 0;
                    }
                if(blocks[i/3*3 + j/3][SUDOKU[i][j]] > 1)
                {
                    flag = 0;
                }
            }
        }        


        printf("Instancia %d\n",k);
        
        if(flag) 
            printf("SIM\n");
        else 
            printf("NAO\n");

        ENDLINE
    }

}