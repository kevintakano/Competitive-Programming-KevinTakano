
#include <bits/stdc++.h>


using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define for0(i,N) for(int i =0;i < N;i++)
#define for1(i,N) for(int i =1;i <= N;i++)
#define forab(i,a,b) for(int i =a;i <= b;i++)
#define ps(s) printf("%s\n",s);

typedef long long int ll; 


int main()
{
	double N,L,D;

	double building[100];

	while(cin >> N >> L >> D)
	{
		int gardem_position = 0;
		double value;

		for0(i,N){
			cin >> value;
			if(value == 0)	gardem_position = i; 
			building[i] = value;
		}	

		double sum = 0;

		double right_angle = 0, left_angle = 0;
		// printf("gardem_position %d\n",gardem_position);
		for(int i = gardem_position + 1; i < N;i++)
		{
			sum += L + D;
			if(right_angle < atan2(building[i],sum)) right_angle = atan2(building[i],sum);
		}
		sum = 0;
		for(int i = gardem_position - 1; i >=0;i--)
		{
			sum += L + D;
			if(left_angle < atan2(building[i],sum)) left_angle = atan2(building[i],sum);
		}
		// printf("right_angle %lf, left_angle %lf\n",right_angle,left_angle);
		double total_angle =  180.0 - right_angle*(180.0/M_PI) - left_angle*(180.0/M_PI);
		// printf("total_angle %lf\n",total_angle);
		printf("%.2lf\n",total_angle*(16*60)/	180.0);
	}


	return 0;
}