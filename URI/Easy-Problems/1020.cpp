#include <cstdio>
#include <iostream>

#define ENDLINE printf('\n');
#define END ('\n')
#include <cmath>

using namespace std;

int main()
{
	int E;

	cin >> E;

	int anos = E / 365; 

	E = E - 365 * anos; 

	int meses = E / 30;

	E = E - 30 * meses; 

	int dias; 

		dias = E; 

/*
	cout << anos << " ano(s)"  << END; 
	cout << meses << " mes(es)"  << END; 
	cout << dias << " dias(s)"  << END; 

*/
	printf("%d ano(s)\n",anos);
	printf("%d mes(es)\n",meses);
	printf("%d dia(s)\n",dias);

	return 0;
}