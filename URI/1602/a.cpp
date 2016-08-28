
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

bitset<MAX> bs;
vi primes(MAX);
bitset<MAX> hp; 

ll sieve_size; 

bool perfect_square(long long n){
    long long squareRootN=(long long)	((sqrt(n)));

    if(squareRootN*squareRootN == n) {
        return true; 
    }
     else {
        return false; 
     }
 }

int number_divisors(ll N)
{
	int count = 0;

	for(int i = 2; i < sqrt(N);i++)
	{
		if(N % i == 0) count++;
		// printf("valor i %d\n",i);
	}	

	count +=1;
	count *= 2;
	count+= 1;

	// printf("count final %d de N %lld\n",count,N);

	return count;
}

void sieve_hiperprimes(ll upperbound, int answer[MAX])
{
	sieve_size = upperbound + 1;
	bs.set(); // todos os bits vão para 1
	hp.reset(); // inverso
	bs[0] = bs[1] = 0;

	for(ll i = 2; i <= sqrt(sieve_size)	;i++)
	{
		if(bs[i])
		{
			for( ll j = i*i ; j <= sieve_size; j+= i)
			{
				bs[j] = 0;
			}
			// primes.push_back(i);
		}	
	}

	for(int i = 2 ; i <= sieve_size;i++)
	{
		if(bs[i])
		{
			hp[i] = true;
		}else 
		{

			if(perfect_square(i))
			{
				// cout << "number = " << number_divisors(i) << END;

				if(bs[number_divisors(i)])
				{
					hp[i] = true;
				} else 
				{
					hp[i] = false;
				}
			} else 
			{
				hp[i] = false;
			} 
		}
	}

	memset(answer,0,sizeof answer[0] * MAX);
	answer[0] = 1; // 0 é o 2 

	for(int i = 1; i < MAX; i++)
	{
		answer[i] = answer[i-1];
		if(hp[i+2]) answer[i]++; 
	}	
}


int main()
{
	int answer[MAX];
	sieve_hiperprimes(MAX,answer);
	int N;

	while(cin >> N)
	{
		cout << answer[N-2] << END;
	}

	return 0;
}