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

	int A,B,C,D;

	cin >> A >> B >> C >>D;

	if(B > C && D > A && (C+D) > (A+B) && C > 0 && D > 0 && A % 2 == 0){
		cout << "Valores aceitos" << END;
	} else 
	{
		cout << "Valores nao aceitos\n";
	}
	

	return 0;
}