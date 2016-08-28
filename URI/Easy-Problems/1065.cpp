
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

typedef long long int ll; 

int main()
{
	int a,b,c,d,e;

	cin >> a >> b >> c >> d >> e >> f;
	int count = 0;
	if(a % 2 == 0) count ++;
	if(b % 2 == 0) count ++;
	if(c % 2 == 0) count ++;
	if(d %2 == 0) count ++;
	if(e % 2== 0) count ++;
	
	printf("%d valores pares\n",count);

	return 0;
}