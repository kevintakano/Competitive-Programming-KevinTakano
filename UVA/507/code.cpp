#include <bits/stdc++.h>
int number_routes;
int stops[20*1000 + 2];
int PD[20*1000 + 2];


using namespace std;

bool solve(int n_stops)
{
	PD[1] = stops[1];
	for(int i = 2; i <= n_stops; i++)
	{
		PD[i] = max(PD[i-1] + stops[i], stops[i]);
	}	

	for(int i = 1;i <= n_stops; i++)
	{
		cout << " " << PD[i] ;
	}
		cout << " $ " << endl;
	cout << *max_element(PD,PD+n_stops) << endl;

}

int main()
{
	cin >> number_routes;
	
	for(int i = 0;i < number_routes;i++)
	{
		memset(PD,0,sizeof(int)*(number_routes+1));

		int n_stops;
		cin >> n_stops;
		n_stops--;
		for(int j = 1;j <= n_stops;j++)
		{
			cin >> stops[j];
		}

		solve(n_stops);	
	}

	return 0;
}
