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

	for(int i = 1; i < 101;i++)
	{
		if( i % 2 == 0)		cout << i << END;
	}

	return 0;
}