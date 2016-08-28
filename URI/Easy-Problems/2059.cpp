#include <cstdio>
#include <iostream>
#include <vector> 
#include <algorithm> 

#define ENDLINE printf('\n');
#define END ('\n')
#include <cmath>

using namespace std;

int main()
{

	int	p, j1,j2,r,a;

	cin >> p >> j1 >> j2 >> r >> a ;

	if( (j1 + j2) % 2 == (!p)  && r == 0 && a == 0)
	{
		cout << "Jogador 1 ganha!" << END;
	} else if( (j1 + j2) % 2 != (!p)  && r == 0 && a == 0)
	{
		cout << "Jogador 2 ganha!" << END;
	} else 
	{
		if(r == 0 && a == 1)
		{
			cout << "Jogador 1 ganha!" << END;
		} else if(r == 1 && a == 1)
		{
			cout << "Jogador 2 ganha!" << END;
		} else if(r == 1 && a == 0)
		{
			cout << "Jogador 1 ganha!" << END;
		}
	}
	return 0;
}