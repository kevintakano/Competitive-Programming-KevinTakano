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

#define MAX 10000

int main()
{
	double R,x1,y1,r,x2,y2; 
	
	while(cin >> R >> x1 >> y1 >> r >> x2 >> y2) // caçador / flor
	{
		// a distancia máxima entre os dois círculos será quando dist(c1,c2) for igual (R-r). E será menor que (R-r) quando se mover o circulo menor mais perto do centro;
		double dx = (x1-x2)*(x1-x2), dy = (y1-y2)*(y1-y2);
		double d = (sqrt(dx + dy));
		
		if(d <= (R-r))
		{
			printf("RICO\n");
		} else printf("MORTO\n");
	}
}





