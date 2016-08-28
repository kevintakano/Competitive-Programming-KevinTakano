#include <bits/stdc++.h>

using namespace std;

#define end '\n';

typedef long long ll;

bool perfect_square(ll n)
{
	double r = round(sqrt(n));
	return r*r == n;
}

int main()
{
	ll t,n;
	cin >> t;
	ll inst=0;
	for(int i = 0; i < t;i++)
	{	
		inst++;
		cin >> n;
		ll s = n;
		while(!perfect_square(s))
		{
			s += n;
			//printf(" n  = %lld\n",s);
		}
		cout << "Caso #" << inst << ": " << s << end;
	}
}
