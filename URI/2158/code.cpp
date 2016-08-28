#include <bits/stdc++.h>

using namespace std;

#define end '\n';

int  main()
{
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long  fp,fh;
	unsigned long long  mol = 0;//moleculas
	unsigned long long  arestas, vertices;
	while(cin >> fp >> fh)
	{	
		mol++;
		cout << "Molecula #" << mol << ".:." << end;
		//prunsigned long long f("fp %d e fh %d\n",fp*5,fh*6);
		arestas = (fp*5 + fh*6)/2;
		vertices = arestas + 2 - (fp + fh);
		
		cout << "Possui " << vertices << " atomos e " << arestas << " ligacoes" << end;
		cout << end;
		
		
	}
}
