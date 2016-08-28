
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
	float a,b,c,d,e,f;

	cin >> a >> b >> c >> d >> e >> f;
	int count = 0;
	float  sum = 0;
	if(a > 0) {count ++;sum+=a; }
	if(b > 0) count ++,sum+=b;
	if(c > 0) count ++,sum+=c;;
	if(d > 0) count ++,sum+=d;
	if(e > 0) count ++,sum+=e;
	if(f > 0) count ++,sum+=f;
	
	printf("%d valores positivos\n",count);
	printf("%.1f\n",(sum)/count);

	return 0;
}