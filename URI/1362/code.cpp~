#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
 
#define pm(mapa,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mapa[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

//XXL, XL, L, M, S e XS
vector< vector<char> > mapa;	

int est_cam[7]; // estoque_camisas
int cam_vol[31][2]; // camisas voluntários

bool ver_poss(vector<int> &sol) // verifica possibilidade de estar no estoque
{

	int buf_est_cam[7]; 
	memcpy(buf_est_cam,est_cam,sizeof est_cam);
	for(auto &obj: sol)
	{
		if(buf_est_cam[obj] == 0) return false;
		else buf_est_cam[obj]--;
	}
	return true;
}

bool solve(vector<int> &sol, int ESTADO, int &M, const int &pos)
{
	if(sol.size() == M)
	{
		return ver_poss(sol); // verifica possibilidades
	}
	for(int i = pos; i <= M;i++)
	{
		for(int est = 0; est <= 1; est++)
		{		
			
			sol.push_back(cam_vol[i][est]);
			if(solve(sol,est, M,pos) == true) return true;
			sol.pop_back();
		}
	}
	return false;
}

int main()
{
	int T;
	int N,M;
	
	cin >> T;
	
	for0(i,T)
	{	
		memset(est_cam,0,sizeof est_cam);
		memset(cam_vol,0,sizeof cam_vol);		

		cin >> N >> M;
		
		int total_cam_est = N/6; //camisas total por tipo
		
		for1(i,6)
		{
			est_cam[i] = total_cam_est;
		}
		
		for1(i,M)
		{
			for0(k,2)
			{
				char value[3]; cin >> value;
				
				if(strcmp(value,"XXL")) cam_vol[i][k] = 1;
				if(strcmp(value,"XL")) cam_vol[i][k] = 2;
				if(strcmp(value,"L")) cam_vol[i][k] = 3;
				if(strcmp(value,"M")) cam_vol[i][k] = 4;
				if(strcmp(value,"S")) cam_vol[i][k] = 5;
				if(strcmp(value,"XS")) cam_vol[i][k] = 6;														
			}			
		}
		
		/*printf("Est_cam\n");
		
		for1(i,6)
		{
			printf("[%d]",est_cam[i]);
		} ENDLINE;
		
		for1(i,M)
		{
			printf("[%d,%d]",cam_vol[i][0],cam_vol[i][1]);
		} ENDLINE;
		*/
		
		
		vector<int> sol; 
		if(solve(sol,0,M,1))
		{
			printf("YES\n");
		}else printf("NO\n");
	}
}
















