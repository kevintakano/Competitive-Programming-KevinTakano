		

#include <bits/stdc++.h>

#define MAX (2*1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")

using namespace std; 

typedef 	long long ll;
typedef std::vector<int> vi;


bool perfect_square(int k)
{
	int root = sqrt(k);
	if(root*root == k) return true; else return false;
}

bitset<1000000> bs;
vi primes;
ll sieve_size; 

void sieve(ll upperbound)
{
	sieve_size = upperbound + 1;
	bs.set(); // todos os bits vão para 1
	bs[0] = bs[1] = 0;

	for(ll i = 2; i <= sieve_size;i++)
	{
		if(bs[i])
		{
			for( ll j = i*i ; j <= sieve_size; j+= i)
			{
				bs[j] = 0;
			}
			primes.push_back((int)i);	
		}
	}
}

bool isPrime(ll N)
{
	if(N <= sieve_size) return bs[N];

	for(int i = 0; i < (int) primes.size();i++)
	{
		if(N % primes[i] == 0)
		{
				return false;
		}
	}
	return true;
}

int divisors(int k)
{
	bool isprime = 1;

	int count = 0;

	for(int i = 1; i <= k;i++)
	{
		if(k % i == 0)
		{
			count++;
		}
	}

	return count;
}

bool perfect_square(long long n){
    long long squareRootN=(long long)round((sqrt(n)));

    if(squareRootN*squareRootN == n) {
        return true; 
    }
     else {
        return false; 
     }
 }
int main()
{
	sieve(100000);


	int N;

	int conta = 0;

	for(int i = 1 ;i <= 250 ;i++)
	{

		int count = divisors(i);

		if(isPrime(count)) conta++;

		// cout << "i = " << i << " " << count << " " <<	isPrime(count) << END;		

		printf("i = %d (Eh primo? %d), Numero de divisores %d (Eh primo? %d)\n",i,isPrime(i),count,isPrime(count)); 
		
		if(isPrime(count) != isPrime(i))
		{
			printf("ACHEI UM CARA QUE EH HIPERPRIMO MAS N É PRIMO!					VALOR  DO I = %d, SQRT(I) = %lf (RAIZ EH PRIMO? (%d))\n",i,sqrt(i),isPrime(sqrt(i)));
		}
		if(perfect_square(i))
		{
			printf("SOU UM QUADRADO PERFEITO ************* %d , sqrt(i) = %lf (RAIZ PRIMO? %d)\n",i,sqrt(i),isPrime(i));
		}
	}

	cout << conta << END;


	return 0;
}