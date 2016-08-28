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

	int A,B,C;
	cin >> A >> B >> C;

	int vet[3] = {A,B,C};

	vector<int> vet2(vet, vet + 3);

	auto it = max_element(vet2.begin(),vet2.end());

	cout << *it << " eh o maior" << END; 

	return 0;
}