#include <cstdio>
#include <iostream>
#define PI (3.14159)
using namespace std;

int main()
{
	double R;

	cin >> R;

	printf("VOLUME = %.3lf\n",(4.0/3.0) * PI * R * R * R );

	return 0;
}