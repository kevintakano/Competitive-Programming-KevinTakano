#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 


using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");

int mdc(int a,int b)
{
    if(b == 0) return a;
    else
    return mdc(b,a%b); // 2,3 -> mdc(3,2) -> mdc(3,1) -> mdc(1,3%1)
}
int mmc(int a,int b)
{
    int div_;
    if(b == 0) return a;
    else
     div_ = (a*b)/(mdc(a,b));
    return (div_); 
}      
       

int main()
{
	int N,A,B;

	scanf("%d %d %d",&N,&A,&B);

	do
	{
		int count = 0;

		int mmc_ = mmc(A,B);

		//printf("mmc %d\n",mmc(A,B));

		printf("%d\n",N/A + N/B - N/mmc_);

		scanf("%d %d %d",&N,&A,&B);

	} while(N != 0 && A != 0 && B != 0);

	return 0;
}