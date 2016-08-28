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

struct wheel
{
    int a,b,c,d;

    bool operator==(const wheel &w)
    {
        return  a == w.a && b == w.b && c == w.c && d == w.d;
    }
    bool operator<(const wheel &w)
    {
        return (a*1000 + b*100 + c*10 + d) < (w.a*1000 + w.b*100 + w.c*10 + w.d);
    }
    void print()
    {
        printf("%d%d%d%d\n",a,b,c,d);
    }
    wheel(int x,int y,int z,int w)
    {
        a = x, b = y, c = z, d = w;
    }
    
    wheel()
    {

    }
};

struct node
{
    wheel w; 
    int level;

    node()
    {

    }
    node(const wheel &wh,const int &l)
    {
        w.a = wh.a;
        w.b = wh.b;
        w.c = wh.c;
        w.d = wh.d;
        level = l;
    }
};

// bool forbidden[10001];
bool visited[10001];
queue<node> q;

int to_number(wheel bla)
{
    return (bla.a*1000) + bla.b*100 + bla.c*10 + bla.d;
}

int main()
{

    int N;

    cin >> N;

    for(int xablay = 0; xablay < N;xablay++)
    {
        // memset(forbidden,0,sizeof forbidden);
        memset(visited,0,sizeof visited);

        wheel init,target;

        cin >> init.a >> init.b >> init.c >> init.d;

        cin >> target.a >> target.b >> target.c >> target.d;

        printf("init : "); init.print();
        printf("target : "); target.print();
        
        int n;
        cin >> n;

        for0(i,n)
        {
            wheel temp;
            cin >> temp.a >> temp.b >> temp.c >> temp.d;
            visited[to_number(temp) ] = 1;
        }

        visited[to_number(init)] = 1;

        for(int k = 0; k < 4;k++)
        {
            for(int i = 1; i <= 9;i++)
            {
                if(k == 0 && init.a != i)
                {
                    wheel w = wheel( (init.a + i) % 10,init.b,init.c,init.d) ;
                    if(!visited[to_number(w)])
                        printf("init.a %d, i %d %d\n",init.a,i,((10-init.a)+i)%10),q.push(node(w,min((init.a - (init.a + i)%10,((10-init.a)+(init.a + i)%10)%10)));
                }
                if(k == 1 && init.b != i)
                {
                    wheel w = wheel(init.a,i,init.c,init.d) ;
                    if(!visited[to_number(w) ])
                        q.push(node(w,min((init.b - (init.b + i)%10),((10-init.b)+(init.b + i)%10)%10)));
                }
                if(k == 2 && init.c != i)
                {
                    wheel w = wheel(init.a,init.b,i,init.d) ;
                    if(!visited[to_number(w)])
                        q.push(node(w,min((init.c - (init.c + i)%10),((10-init.c)+(init.c + i)%10)%10)));
                }
                if(k == 3 && init.d != i)
                {
                    wheel w = wheel(init.a,init.b,init.c,i) ;
                    if(!visited[to_number(w)])
                        q.push(node(w,min((init.d - (init.d +i)%10),((10-init.d)+(init.d+i)%10)%10)));
                }
            }
        }  
       
        int count = 0;
        int found = 0;
        while(!q.empty())
        {
            node n = q.front();
            wheel top = n.w;
            int level = n.level;
            q.pop();

            if(visited[to_number(top)]) continue;

            visited[to_number(top)] = 1;

            top.print(); printf("::: %d\n",level);  

            if(top == target) {  found =1; count = level; ;break;}


           /* for(int k = 0; k < 4;k++)
            {
                for(int i = 1; i <= 9;i++)
                {
                    if(k == 0 && init.a != i)
                    {
                        wheel w = wheel( (init.a + i) % 10,init.b,init.c,init.d) ;
                        if(!visited[to_number(w)])
                            q.push(node(w,min(abs(init.a - i),((10-init.a)+i)%10)));
                    }
                    if(k == 1 && init.b != i)
                    {
                        wheel w = wheel(init.a,i,init.c,init.d) ;
                        if(!visited[to_number(w) ])
                            q.push(node(w,min(abs(init.b - i),((10-init.b)+i)%10)));
                    }
                    if(k == 2 && init.c != i)
                    {
                        wheel w = wheel(init.a,init.b,i,init.d) ;
                        if(!visited[to_number(w)])
                            q.push(node(w,min(abs(init.c - i),((10-init.c)+i)%10)));
                    }
                    if(k == 3 && init.d != i)
                    {
                        wheel w = wheel(init.a,init.b,init.c,i) ;
                        if(!visited[to_number(w)])
                            q.push(node(w,min(abs(init.d - i),((10-init.d)+i)%10)));
                    }
                }
            }  */
               
        }

        char c;
        scanf("%c",&c);
        printf("C CARALHO %c\n",c);

        if(found) printf("porra %d\n",count);
        else printf("-1\n");       
    }

}