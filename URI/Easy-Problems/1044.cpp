
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;

	cin >> a >> b;

	if(a > b)
	{
		swap(a,b);
	}

	if(b % a == 0)
	{
		printf("Sao Multiplos\n");
	}else 
	{
		printf("Nao sao Multiplos\n");

	}
}