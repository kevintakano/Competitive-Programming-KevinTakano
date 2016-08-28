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
int MAX;

        

void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  



char strings[100][100];

int main()
{
    int N, K;

    while(cin >> N >> K)
    {
        if(!N && !K) break;
        for0(i,N)
        {
            cin >> strings[i];
        }       
        MAX = K;

        int swaps = 0;

        for(int i = 1; i < N;i++)
        {
            for(int j = 0; j < N - i;j++)
            {
                if(strcmp(strings[j],strings[j+1]) > 0) // strings[j] < string[j+1]
                {
                    char buffer[100];
                    if(swaps == K) break;
                    strcpy(buffer,strings[j+1]);
                    strcpy(strings[j+1],strings[j]);
                    strcpy(strings[j],buffer);
                    swaps++;
                }
            }
            // swap(strings[minor],strings[i]);
        }
        for0(i,N)
        {
            printf("[%s]",strings[i]);
        } 
        ENDLINE;
    }


}