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

	double x1,x2,y1,y2;

	cin >> x1 >> x2 >> y1 >> y2;
	

	printf("%.4f\n",sqrt((x1 -y1)*(x1 -y1) + (y2-x2)*(y2-x2)));



	return 0;
}