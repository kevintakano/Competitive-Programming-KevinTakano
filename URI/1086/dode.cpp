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

int tabuas[MAX + 1];
int tabuas2[MAX + 1];

int main()
{
    int M,N,L;
    int K;
    while(cin >> M >> N && M && N)
    {

        cin >> L;
        cin >> K;
    	//memset(tabuas,0,sizeof(int)*K);
    	//memset(tabuas2,0,sizeof(int)*K);              
        for(int i = 0; i < K; i++)
        {	
            int value;
            cin >> value; tabuas[i]= (value*100);
            tabuas2[i] = (value*100);
        }   
           	
	M *= 100; N *= 100;
        //printf("largura M = %d e Altura N %d\n",M,N);
        int c=0,h=0,h2=0,c2=0;   
        int count = 0;       
	int count2 = 0;
        bool found = false;
        
        bool final1 = false, final2 = false;

	sort(tabuas, tabuas + K,[](int a, int b){return a > b;});	
	
	for(int i = 0; i < K;i++) tabuas2[i] = tabuas[i]; 
	
	int removeds = 0;
	
        while(h < M && count < K && count >= 0 && c >= 0 && h >= 0 && removeds < K)
        {
	    	c = 0;   	
		bool found = true;
		int last_inserted = 0;
		while(c < N && count < K && found == true && removeds < K)
		{ 	    
			found = false;	
			for(int i = 0; i < K;i++)
			{
			    if(N - c >= tabuas[i] && tabuas[i] != -1)                    
			    {
				c += tabuas[i];
				last_inserted = tabuas[i];
				//printf("inseri o %d\n",tabuas[i]);
				tabuas[i]  = -1;
				removeds++;
				found = true;	            	                         	
				count++;				
				break;
			    } 		
			}
		}       
		if(found == false && c != N) { h -= L; c -=  last_inserted; count--; } ;
		//printf("h = %d, count = %d, K = %d, M = %d, removeds %d, c = %d",h,count,K,M,removeds,c);
		//printf("found = %d\n",found);
		h += L;
        }       
 	if(h == M && c == N) final1 = true;
 	
 	swap(M,N); 
 	h = 0, c = 0; 
 	removeds = 0;
 	//printf("After!\n");
 	
 	while(h < M && count2 < K && count2 >= 0  && c >= 0 && h >= 0 && removeds < K)
        {
	    	c = 0;   	
		bool found = true;
		int last_inserted = 0;
		while(c < N && count2 < K && found == true && removeds < K)
		{ 	    
			found = false;
			for(int i = 0; i < K;i++)
			{
			    if(N - c >= tabuas2[i] && tabuas2[i] != -1)                    
			    {
				c += tabuas2[i];
				last_inserted = tabuas2[i];
				//printf("inseri o %d\n",*it);
				tabuas2[i]  = -1;
				removeds++;
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
