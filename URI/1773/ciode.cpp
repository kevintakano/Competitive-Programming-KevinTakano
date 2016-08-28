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


const int MAXN = 1005;

std::vector<bool> vis(MAXN), done(MAXN);
std::vector<int> adj[MAXN], res;
std::vector<int> keys(MAXN );
std::vector<bool> have_key(MAXN);

int total_visiteds = 0;

void dfs(int u) {
    // if (vis[u])
    // throw std::runtime_error("Not a DAG.");
    //printf("keys[u=%d] %d\n",u,keys[u]);
    have_key[keys[u]] = true;

    vis[u] = true;
    
    if (done[u])
        return;

    for (int j = 0; j < (int)adj[u].size(); j++){
        if(have_key[adj[u][j]] && !vis[adj[u][j]]) dfs(adj[u][j]);
    }
    done[u] = true;
    if(done[u]) 
        total_visiteds++;
    //res.push_back(u);
}


int main() {

    int N,M;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int i = 0;
    while(cin >> N >> M && i <= 70)
    {
        i++;
        keys.clear();
        for(auto &obj : adj)
        {
            obj.clear();
        }

        fill(done.begin(), done.end(), false);
        fill(have_key.begin(), have_key.end(), false);
            

        i++;
        total_visiteds = 0;
        for0(i,M)
        {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 2; i <= N;i++)
        {
            int value;cin >> value;
            keys[value] = i; // para ir na sala value, vc tem que ter a chave da sala i
        }
        have_key[1] = true;
        dfs(1); 
        //printf("total_visiteds %d\n",total_visiteds);
        if(total_visiteds == N) cout << "sim" << '\n'; else cout << "nao" << '\n';

    }





  return 0;
}