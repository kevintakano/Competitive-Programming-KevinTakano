#include <bits/stdc++.h>
#include <bitset> 

using namespace std;

#define end '\n';

typedef long long ll;
typedef vector<ll> vll;
ll _sieve_size;

bitset<1000000000> bs;
vector<ll> primes;

/*
Então podemos concluir que se o número possui apenas expoente pares para os fatores de sua fatoração prima ele é um quadrado perfeito.
*/

void sieve(ll ub)  // ub = upperbound
{
	ub = sqrt(ub) + 1;
	
	bs.set(); // set all bits to 1
	bs[0] = bs[1] = 0;
	
	for(ll i = 2; i <= ub;i++)
	{
		if(bs[i])
		{
			for(ll j = i*i;j <= ub; j+=i)
			{
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

ll prime_factors_perfect_square(ll N)
{
	//vll factors;
	ll answ = 1;
	ll PF_idx = 0, PF = primes[PF_idx];
	int count = 0;
	
	while(PF*PF <= N)
	{
		count = 0;			
		while(N % PF == 0)
		{
			N /= PF;
			answ *= PF;
			count++;
		}		
		if(count % 2 != 0) answ *= PF;
		
		PF = primes[++PF_idx];
	}

	if(N != 1) answ*=PF*PF;

	//printf("1 N %d count = %d e answ %lld e PF %lld\n",N,count,answ,PF);
	return answ;
}


int main()
{
	ll t,n;
	cin >> t;
	ll inst=0;
	
	sieve(1000000000);
	
	for(int i = 0; i < t;i++)
	{	
		inst++;
		cin >> n;
		
		n = prime_factors_perfect_square(n);
				
		cout << "Caso #" << inst << ": " << n << end;
	}
}
