#include <stdio.h>
#define MAX 100

int invalid_pos(int row, int col, int x , int y )
{
	return row >= y || row < 0 || col < 0 || col >= x; 
}

int main()
{
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);

	char mapa[MAX][MAX];

	int row = 0,col =0 ;

	int length_path = 0;

	int incorrect_map = 0;

	int situation_selected = -1;

	while( ( length_path < x*y ) && (incorrect_map == 0) && mapa[row][col] != '*')
	{
		mapa[row][col] = 'x'; 
		if(mapa[row][col] == '>')
		{ 
			col++;
			situation_selected = 0;
		}
		
		if(mapa[row][col] == '<')
		{
			col--;
			situation_selected = 1;		
		}	
	
		if(mapa[row][col] == '^')
		{
			row--;
			situation_selected = 2;			
		}	
		
		if(mapa[row][col] == 'v')
		{
			row++;
			situation_selected = 3;			
		}	

		if(mapa[row][col] == '.' && situation_selected == 0) col++;
			
		if(mapa[row][col] == '.' && situation_selected == 1) col--;

		if(mapa[row][col] == '.' && situation_selected == 2) row--;

		if(mapa[row][col] == '.' && situation_selected == 3) row++;

		if(mapa[row][col] == 'x')	incorrect_map = 1;
		
		length_path++;

		if(invalid_pos(row,col,x,y)) incorrect_map = 1;


	}
	
	if(incorrect_map == 1)
		printf("!\n");
	else
		printf("*\n");

	return 0;
}
