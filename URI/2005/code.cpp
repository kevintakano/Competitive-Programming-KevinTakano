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

// int h[1000];

multiset<int> h;

int s[1000];


int main()
{
    int N,M;

    while(cin >> N >> M)
    {   
        h.clear();
        memset(s,0,sizeof s);

        for0(i,N)
        {
            int value;
            cin >> value;
            h.insert(value);
        }
        for0(i,M)
        {
            cin >> s[i];
        }

        int saciateds = 0;
        int i = 0;
        int found = 0;
        while(i < M && h.size() != 0)
        {   
            found = 0;
            // printf("s[i = %d] %d\n",i,s[i]);
            // for(auto obj: h) printf("[%d]",obj); ENDLINE;
            auto it  = h.rbegin();
            for(; it!= h.rend(); it++)
            {
                if(s[i] >= *it) {found = 1; break;}
            }

            if(found)
            {
                // printf("found with s[i] = %d\n",s[i]);
                // printf("*it = %d\n",*it);
                h.erase(--it.base()); saciateds++;
            } else 
            {
                // if(s[i] >= *last)
                auto last = h.end();
                int value = *prev(last);
                // printf("aqui "); for(auto obj: h) printf("[%d]",obj); ENDLINE;
                h.erase(prev(last));

                h.insert(value - s[i]);
            }


            i++;
        }
            // pa(h,N);


        printf("%d\n",saciateds);
    }




}