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


// Driver program to test methods

bool eh_pitagorica(int x, int y, int z)
{
return (x*x == y*y + z*z) || (y*y == x*x + z*z) || (z*z == x*x + y*y);
}

int main()
{

ios_base :: sync_with_stdio(0);
cin.tie(0);


  int x,y,z;

  while(cin >> x >> y >> z)
  {
    bool eh_pit = eh_pitagorica(x,y,z);

    if(  __gcd(x,__gcd(y,z)) == 1   && eh_pit )
    {
      printf("tripla pitagorica primitiva\n");
    } else if(eh_pit)
    {
      printf("tripla pitagorica\n");
    }
    else printf("tripla\n");
  }


  return 0;
}