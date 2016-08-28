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

bool map_no_op(char c)
{
	return c != 'v' && c != '>' && c != '<' && c != '^';
}

int main()
{
	int WIDTH,HEIGHT;

	cin >> WIDTH;

	cin >> HEIGHT;

	FOR(i,HEIGHT) FOR(j,WIDTH) cin >> MAP[i][j];

	bool found = false;
	bool contin = false;

	int i = 0, j = 0;
	char last = '0';
	last = MAP[i][j];



	while(i < HEIGHT && j < WIDTH && found == false && i >= 0 && j >= 0 && MAP[i][j] != '*')
	{
		char p = MAP[i][j];

		if(p == '>')
		{
			last = '>';
		}else 
		if(p == 'v')
		{
			last = 'v'; 
		}else 
		if(p == '<')
		{
			last = '<';
		}else 
		if(p == '^')
		{
			last = '^';
		}

		if(last == '>')
		{
			MAP[i][j] = 'x';
			j++;
		}else 
		if(last == 'v')
		{
			MAP[i][j] = 'x';
			i++;
		}else 
		if(last == '<')
		{
			MAP[i][j] = 'x';
			j--;
		}else 
		if(last == '^')
		{
			MAP[i][j] = 'x';
			i--;
		}


	}
	/*for(int a = 0; a < WIDTH;a++)
	{
		for(int b = 0; b < HEIGHT; b++)
		{
			printf("[%c]",MAP[a][b]);
		}
		ENDLINE;
	}*/

	if(MAP[i][j] == '*') printf("*\n"); else printf("!\n");
	
	return 0;
} 