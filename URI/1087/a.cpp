#include <cstdio>
#include <iostream>

#define ENDLINE printf('\n');

#include <cmath>

using namespace std;

int main()
{
	int x1,x2, y1,y2; 

	while(1)
	{
		cin >> x1 >> x2 >> y1 >> y2;

		if(x1 == x2 && y1 == y2 && y1 == 0 && x1 == 0)
		{
			break;
		}

		int res;
		if(x1 == y1 && x2 == y2)
		{
			printf("0\n");
		}
		else if(y2 ==  x2 || x1 == y1 || (y1 + y2) == (x1 + x2) || abs(x1-y1) == abs(x2-y2))// coluna iguais , linhas iguais
		{
			printf("1\n");
		} else 
		{
			printf("2\n");
		}
		
	}





	return 0;
}