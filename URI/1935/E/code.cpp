
#include <bits/stdc++.h>


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

#define ps(s) printf("%s\n",s);
#define MOD 1000000009
typedef long long int ll; 
typedef unsigned long long int llu; 

ll extern_table(int i,int N)
{
	return 4*(N - 2*i) - 4;
}


void print_array(ll array[], const ll &N)
{
	for(int i =0 ; i < N;i++)
	{
		printf("[%lld]",array[i]);
	}ENDLINE;
}
int main()
{
	ll n,b;
	cin >> n >> b;
	ll sum = 0;	
	ll init = 0;
	ll end = n/2;
	ll mid,beans = 0;

	while(init + 1 < end)
	{
		mid = (init + end) / 2; 
		beans = 4 * mid *(n-mid);

		if(beans <= b)
			init = mid;
		else 
			end = mid;
	}
	beans = 4*init*(n-init);
	b -= beans;

	// printf("init = %lld\n",init);
	// printf("beans = %lld\n",b);

	ll max = n - 2*(init);
	
	// printf("max = %d\n",max);


	int	l = 0,c = 0;
	if(init == 0)
		l = 0, c = -1;	
	else 
		l = init, c = init - 1;
	// printf("l = %d e c = %d\n",l,c);

	if(b < max && b )
	{
		c += b; 
		b = 0; 
	}else if(b)
	{
		b -= max; 
		c += max;
	}
	max--;
	if(b < max && b)
	{	
		l += b; 
		b = 0;
	}else if(b)
	{
		b -= max; 
		l += max;
	}
	if(b < max && b )
	{
		c -= b; 
		b = 0; 
	}else if(b)
	{
		b -= max; 
		c -= max;
	}
	max--;
	if(b < max && b)
	{	
		l -= b; 
		b = 0;

	}else if(b)
	{
		b -= max; 
		l -= max;
	}


	// printf("l = %d, c = %d\n",l,c);

	printf("%d %d\n",l+1,c+1);

	// print_array(vb,n/2 + 1);


}