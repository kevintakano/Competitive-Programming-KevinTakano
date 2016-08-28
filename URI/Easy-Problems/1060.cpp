
#include <bits/stdc++.h>

using namespace std;

int main()
{

	double a,b,c,d,e,f;

	cin >> a >> b >> c >> d >> e >> f;


	int count = 0;

	if(a>0) count ++;
	if(b>0) count ++;
	if(c>0) count ++;
	if(d>0) count ++;
	if(e>0) count ++;
	if(f>0) count ++;

	printf("%d valores positivos\n",count);

}