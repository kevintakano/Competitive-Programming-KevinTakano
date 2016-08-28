#include <cstdio>
#include <iostream>
#include <cstring> 

using namespace std;

int main()
{	

	int N ;

	cin >> N;

		char A[100],B[100]	;
	

	for(int i = 0; i < N; i++)
	{

		cin >> A >> B;

		int coluna_b = strlen(B) - 1;

		int coluna_a = strlen(A) - 1;

		int count = 0; 

		while(coluna_b >= 0)
		{
			if(A[coluna_a] == B[coluna_b])
			{
				count++;
			}

			coluna_b--;
			coluna_a--;

			if(coluna_a < 0)
			{
				break; 
			}
		}

		if(count == strlen(B))
		{
			cout << "encaixa\n";
		}else 
		{
			cout << "nao encaixa\n";
		}


	}

	return 0; 
}