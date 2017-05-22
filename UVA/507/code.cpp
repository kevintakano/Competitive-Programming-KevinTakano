#include <bits/stdc++.h>
int number_routes;
int stops[20*1000 + 2];
int PD[20*1000 + 2];


using namespace std;

int maxi(int a, int b, int *choice)
{
    if(a >= b)
    {
        *choice = 0;
        return a;
    }
    else
    {
        *choice = 1;
        return b;
    }
}

bool solve(int n_stops, int route)
{
    PD[1] = stops[1];
    int choice;
    int first = 1;
    for(int i = 2; i <= n_stops; i++)
    {
        PD[i] = maxi(PD[i-1] + stops[i], stops[i], &choice);
        if(choice == 1)
        {
            first = i;
        }
    }    
    
    int larger = 1;
    for(int i = 1;i <= n_stops;i++)
    {
        if(PD[i] > larger)
        {
            larger = i;
        }
    }
    if( PD[larger] > 0)
    cout << "The nicest part of route " << route << " is between stops " << first << " and " << larger + 1 << endl;
    else 
    cout << "Route " << route << " has no nice parts" << endl;

}

int main()
{

    ios_base::sync_with_stdio(false);
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

        solve(n_stops,i+1);    
    }

    return 0;
}
