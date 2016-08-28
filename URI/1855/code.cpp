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
	int WIDTH,HEIGHT;

	cin >> WIDTH;

	cin >> HEIGHT;

	FOR(i,HEIGHT) FOR(j,WIDTH) cin >> MAP[i][j];

	printf("W %d H %d\n",WIDTH,HEIGHT);

	int j = 0,found=0;
	int i = 0 ;
	for(j = 0; j < WIDTH;j++)
	{
		if(MAP[0][j] == 'v'){j++; break; }
	}	
	j--;
	if(MAP[0][j]=='*'){ found = 1; printf("*\n"); }
	printf("i = %d e j = %d\n",i,j);
	for(i = 0;i < HEIGHT && !found;i++)
	{
		if(MAP[i][j] == 'v'){i++; break; }
	}
	i--;
	printf("i = %d e j = %d\n",i,j);
	if(MAP[i][j]=='*'){ found = 1; printf("*\n"); }
	for(;j>=0 && !found ;j--)
	{
		if(MAP[i][j] == '^'){j--; break; }
	}
	j++;
	if(MAP[0][j]=='*'){ found = 1; printf("*\n"); }
	printf("i = %d e j = %d\n",i,j);
	for(;i>=0 && !found ;i--)
	{
		if(MAP[i][j] == '*'){i--; break; }
	}	
	i++;
	printf("i = %d e j = %d\n",i,j);
	if(MAP[i][j] == '*' && !found) printf("*\n"); else if(!found) printf("!\n");

	return 0;
} 