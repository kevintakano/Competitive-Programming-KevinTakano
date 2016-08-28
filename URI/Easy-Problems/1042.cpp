
#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")

int main()
{
	int A,B,C;

	cin  >> A >> B >> C;

	vector<int> v {A,B,C}	;

	sort(v.begin(),v.end(),[](int a, int b){return a < b;});

	for(auto &obj : v)
	{
		cout << obj << END;
	}

	ENDLINE;

	cout << A << END << B << END << C << END;

	return 0;
}