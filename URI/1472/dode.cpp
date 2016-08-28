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
 
typedef long long int ll;
 
set<int> points;
 
int main()
{
    int N;
    while(cin >> N)
    {
        int soma = 0;
        for0(i,N)
        {
            int value; cin >> value ;
            soma += value ;
            points.insert(soma);
        }
 
        int arc = soma/3;
 
        // if(arc % 3 != 0) { printf("0\n");continue;}
 
        int number_triangles = 0;
 
        for(auto &obj : points)
        {
            // printf("Current obj %d\n",obj);
             if(obj>arc) break;
            auto it = points.find( (obj + arc ) % soma );
            auto it2 = points.find( (obj + 2*arc ) % soma );
 
            if(it != points.end() && it2 != points.end()) // encontrou
            {
                // printf("it = %d e it2 %d\n",*it,*it2);
                points.erase(it);
                points.erase(it2);
                number_triangles++;
            }
        }
        printf("%d\n",number_triangles);   
        points.clear();
    }
 
 
    return 0;

    }
