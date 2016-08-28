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

int T[MAX + 1];
int T2[MAX+1];


int calc(int M, int N, double L, int K, int *vect)
{
	int total = 0;
	 
	double h = 0;

	for(int i = 0; i < vect[N] && h < (double)M ; i++)
	{
		h += L;
		total++;
		
	}
	//printf("total = %d\n",total);		
	//	for(int i = 0; i <= N;i++) printf("[%d]",vect[i]); printf("\n");
	
//	printf("M %d N %d L %.2f K %d vect[N] %d **********************\n",M,N,L,K,vect[N]);
	for(int i = 1; i < N && h < M;i++)
	{
		//printf("Total = %d\n",total);
		//printf("vect[i=%d] %d vect[(N-i)=%d] %d\n",i,vect[i],N-i,vect[N-i]);
		//printf("h = %.2f\n",h);
		while(h < M && vect[i] > 0 && vect[N-i] > 0)
		{			
			if(i == N - i && vect[i] < 2 ) 
			{
				//printf("gfoooas222222222222222222dj\n");
				break;
			}
			
			vect[i]--;		
			vect[N-i]--;
			total+=2;
			h += L;
//			printf("	h=%f\n",h);
		}
	}
	//printf("h final %f %d\n",h,M);
	//printf("%d\n",h==(int)M);
	//printf("total = %d\n",total);
	return (round(h) == M) ? total : 0xfffffff;
}

int main()
{
    int M,N; int L;
    int K;
    int inst =0 ;
    while(cin >> M >> N && M && N)
    {
        cin >> L;
        cin >> K;
        memset(T,0,sizeof T);
    	//memset(T2,0,sizeof(int)*K);              
        for(int i = 0; i < K; i++)
        {			
		int value;
		cin >> value;

		T[value]++;
		//printf("value = %d %d\n",value,T[value]);
        }   
     	//for(int i = 0; i <= N;i++) printf("[%d]",T[i]); printf("\n");	
	memcpy(T2,T,sizeof(T));
	
  	int mint = 0xfffffff;
  	//L /= 100;
  	
     	mint = min(mint,calc(M*100,N,L,K,T));      	

     	mint = min(mint,calc(N*100,M,L,K,T2));    
     	inst++;
		//printf("Instancia %d\n",inst); printf("%d %d\n",M,N);
	//if(inst == 29 || inst == 31) printf("HEEEEEEEEEEEEEEEEEEEEEEEEY\n");
	if(mint == 0xfffffff) printf("impossivel\n"); else printf("%d\n",mint);
    }

}
