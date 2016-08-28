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

#define MAX 100000

multiset<int> tabuas;
multiset<int> tabuas2;

int main()
{
    int M,N,L;
    int K;
    while(cin >> M >> N && M && N)
    {
    	if(M == 0 && N == 0) break;
        tabuas.clear();
        tabuas2.clear();
        cin >> L;
        cin >> K;
       
        for(int i = 0; i < K; i++)
        {	
            int value;
            cin >> value; tabuas.insert(value*100);
            tabuas2.insert(value*100);
        }   
           	
	M *= 100; N *= 100;
        //printf("largura M = %d e Altura N %d\n",M,N);
        int c=0,h=0,h2=0,c2=0;   
        int count = 0;       
	int count2 = 0;
        bool found = false;
        
        bool final1 = false, final2 = false;

	
        while(h < M && count < K &&  tabuas.size() != 0 && count >= 0 && c >= 0 && h >= 0)
        {
	    	c = 0;   	
		bool found = true;
		int last_inserted = 0;
		while(c < N && count < K && found == true && tabuas.size() != 0)
		{ 	    
			found = false;
			for(auto it = tabuas.rbegin(); it != tabuas.rend(); it++)
			{
			    if(N - c >= *it)                    {
				c += *it;
				last_inserted = *it;
				//printf("inseri o %d\n",*it);
				tabuas.erase(	--it.base()); // base e usado para pegar o elemento atual no reverse iterator                       
				found = true;	            	                         	
				count++;				
				break;
			    } 		
			}
		}       
		if(found == false && c != N) { h -= L; c -=  last_inserted; count--; } ;
		//printf("h = %d, count = %d, K = %d, M = %d, tabuas.size() %d, c = %d",h,count,K,M,tabuas.size(),c);
		//printf("found = %d\n",found);
		h += L;
        }       
 	if(h == M && c == N) final1 = true;
 	
 	swap(M,N); 
 	h = 0, c = 0; 
 	//printf("After!\n");
 	
 	while(h < M && count2 < K &&  tabuas2.size() != 0 && count2 >= 0  && c >= 0 && h >= 0)
        {
	    	c = 0;   	
		bool found = true;
		int last_inserted = 0;
		while(c < N && count2 < K && found == true && tabuas2.size() != 0)
		{ 	    
			found = false;
			for(auto it = tabuas2.rbegin(); it != tabuas2.rend(); it++)
			{
			    if(N - c >= *it)                    {
				c += *it;
				last_inserted = *it;
				//printf("inseri o %d\n",*it);
				tabuas2.erase(	--it.base()); // base e usado para pegar o elemento atual no reverse iterator                       
				found = true;	            	                         	
				count2++;				
				break;
			    } 		
			}
		}       
		if(found == false && c != N) {  h -= L; c -=  last_inserted; count2--; } ;
		//printf("found = %d\n",found);
		h += L;
        }       
 	if(h == M && c == N) final2 = true;
 	
        if(final1 == true && final2 == true)
		printf("%d\n",min(count,count2));
	else if(final1 == true) printf("%d\n",count);
	else if(final2 == true) printf("%d\n",count2);
	else printf("impossivel\n");
	
	
    }

}
