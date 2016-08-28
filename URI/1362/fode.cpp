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
 
#define pm(mat,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mat[i][j] << "]";    \
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

#include <algorithm> /* std::fill() */
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int match[MAXN], dist[MAXN];
vector<bool> used(MAXN), vis(MAXN);
vector<int> adj[MAXN];

void bfs(int n1, int n2) {
  fill(dist, dist + n1, -1);
  int q[n2], qb = 0;
  for (int u = 0; u < n1; ++u) {
    if (!used[u]) {
      q[qb++] = u;
      dist[u] = 0;
    }
  }
  for (int i = 0; i < qb; i++) {
    int u = q[i];
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = match[adj[u][j]];
      if (v >= 0 && dist[v] < 0) {
        dist[v] = dist[u] + 1;
        q[qb++] = v;
      }
    }
  }
}

bool dfs(int u) {
  vis[u] = true;
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = match[adj[u][j]];
    if (v < 0 || (!vis[v] && dist[v] == dist[u] + 1 && dfs(v))) {
      match[adj[u][j]] = u;
      used[u] = true;
      return true;
    }
  }
  return false;
}

int hopcroft_karp(int n1, int n2) {
  fill(match, match + n2, -1);
  fill(used.begin(), used.end(), false);
  int res = 0;
  for (;;) {
    bfs(n1, n2);
    fill(vis.begin(), vis.end(), false);
    int f = 0;
    for (int u = 0; u < n1; ++u)
      if (!used[u] && dfs(u)) f++;
    if (!f) return res;
    res += f;
  }
  return res;
}



int main()
{
    int T;
    int N,M;
    cin >> T;
    for0(i,T)
    {
        cin >> N >> M;
	for0(i,M+1)
	{
		adj[i].clear();
	}
        for0(j,M)
        {
		int u,v; string a,b;
		int offset = N/6 - 1;
		cin >> a >> b;
		if(!a.compare("XXL"))
		{
		u = 0 ;
		}
		if(!a.compare("XL"))
		{
		u = 1 ;
		}
		if(!a.compare("L"))
		{
		u = 2 ;
		}
		if(!a.compare("M"))
		{
		u = 3 ;
		}
		if(!a.compare("S"))
		{
		u = 4 ;
		}
		if(!a.compare("XS"))
		{
		u = 5 ;
		}
		
		if(!b.compare("XXL"))
		{
		v = 0;
		}
		if(!b.compare("XL"))
		{
		v = 1;
		}
		if(!b.compare("L"))
		{
		v = 2;
		}
		if(!b.compare("M"))
		{
		v = 3;
		}
		if(!b.compare("S"))
		{
		v = 4;
		}
		if(!b.compare("XS"))
		{
		v = 5;
		}
		
		
		for0(w,offset+1)
		{
			adj[u].push_back(j);			
			adj[v].push_back(j);	

			
			//cout << (u) << " " << (v) << " " << w <<  " " << END;
		}
		

        }
        
	int res = hopcroft_karp(M,6*(N/6)); 
	printf("res = %d\n",res);
	if(res == M) printf("YES\n"); else printf("NO\n");
	
	printf("matches :\n");
	
	  for (int i = 0; i < 6*(N/6); i++) {
 	   if (match[i] == -1) continue;
	    cout << match[i] << " " << i << "\n";
}
    }


}
