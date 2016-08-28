
#include <bits/stdc++.h>


using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define FOR(i,N) for(int i =0;i < N;i++)
#define ps(s) printf("%s\n",s);
#define modulo 1000000009

typedef long long int ll; 

void print_matrix(ll  A[3][3], int N){
	FOR(i,N)
	{
		FOR(j,N)
		{
			printf("[%lld]",A[i][j]);
		}ENDLINE
	}
}

void matmult(ll  a[3][3],ll  b[3][3],ll c[3][3])//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]=0;
            for(k=0;k<3;k++)
            {
                c[i][j] = (c[i][j]%modulo + (( a[i][k] % modulo )* ( b[k][j] % modulo ) )%modulo)%modulo ;
            }
        }
    }
 
}
void matpow(ll Z[3][3],ll n,ll ans[3][3])//find ( Z^n )% M and return result in ans
{
 
    ll temp[3][3];
    //assign ans= the identity matrix


	for(int i = 0; i < 3 ; i++) 
	{
		for(int j = 0; j < 3;j++)
		{
			ans[i][j] = 0;
		}
		ans[i][i] = 1;
	}

    int i,j;	
	
   
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp);
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    ans[i][j]=temp[i][j]%modulo;
        }
        matmult(Z,Z,temp);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                Z[i][j]=temp[i][j]%modulo;
 
        n=n/2;
    }



    return;
}



void print_array(ll array[3], int N)
{
	FOR(i,N)
	{
		printf("[%lld]",array[i]);ENDLINE;
	}
}

int main()
{

	ll N;



	while(cin >> N)
	{
		ll  a = 0, b = 1, c = 2;
		if(N == 0) break;
		if(N == 1) printf("%llu\n",a);
		else if(N == 2) printf("%llu\n",b);
		else 
		{
			// printf("N= %llu\n",N);
			ll A[3][3] ;
			memset(A,0,sizeof A);

			ll B[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
			matpow(B,N-3,A);	

			// vector_mul_matrix_inverse(B,C,AUX);
			// print_array(AUX,3);
			// print_matrix(A,3);

			ll value =  ( (A[0][0]) *2 )  + ( (A[0][1])/**1*/) ; 
			value %= modulo;
			printf("%lld\n",value % modulo /*+ (A[0][1] *0 ) % modulo */); // a = 2 , b = 1 , c = 0
		}



	}





}