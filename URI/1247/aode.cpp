#include <bits/stdc++.h>
#define FOR(i,N) for(int i =0;i < N;i++)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
using namespace std;
char MAP[100][100];

int main()
{
	double D, VF,VG;

	while(cin >> D >> VF >> VG)
	{
		double X,Y;
		X = 12.0/VF; // tempo 	

		double P = sqrt(D*D + 144.0);
		// printf("P %lf\n",P);
		Y = P/VG;

		// printf("X %lf Y %lf\n",X,Y);

		if(Y <= X)
		{
			printf("S\n");
		}else 
		{
			printf("N\n");
		}
	}


}