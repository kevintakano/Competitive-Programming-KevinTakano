
#include <bits/stdc++.h>

using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define FOR(i,N) for(int i =0;i < N;i++)

const int MAXN = 1001, INF = 0x3f3f3f3f;;

int dist[MAXN], pred[MAXN];

vector<int> enemy(MAXN);
vector<pair<int, int> > adj[MAXN];

void dijkstra(int start) {
	vector<bool> vis(MAXN, false);
	
	for (int i = 0; i < MAXN; i++) {
		dist[i] = INF;
		pred[i] = -1;
	}
	
	int u, v;
	dist[start] = enemy[start];
	priority_queue<pair<int, int> > pq;
	
	pq.push(make_pair(enemy[start], start));

	while (!pq.empty()) 
	{
		u = pq.top().second;
		pq.pop();
		vis[u] = true;

		for (int j = 0; j < (int)adj[u].size(); j++) 
		{
			if (vis[v = adj[u][j].first])
				continue;

			if (dist[v] > dist[u] + enemy[v]) 
			{	
			/*	printf("v atual %d e u atual %d\n",v,u);
				printf("	enemy[v] = %d\n",enemy[v]);
				printf("	dist[v] %d\n",dist[v]);
				printf("	dist[u] %d\n",dist[u]);*/
				dist[v] = dist[u] + enemy[v];
				pred[v] = u;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
}

void print_path(int dest) {
  int i = 0, j = dest, path[MAXN];
  while (pred[j] != -1)
    j = path[++i] = pred[j];
  cout << "Take the path: ";
  while (i > 0)
    cout << path[i--] << "->";
  cout << dest << ".\n";
}

bool number_of_bullets(int dest, int K)
{
	int i = 0, j = dest, path[MAXN];
  	
	int count = 0;

  	while (pred[j] != -1)
  	{
  		count += enemy[j];
  		j = pred[j];
  	}


  	count += enemy[j];

  	// printf("Numero de balas usadas %d\n",count);

  	return count <= K;
}

/*** Example Usage and Output:
The shortest distance from 0 to 3 is 2.
Take the path: 0->1->3.
***/

int main() {

	int N,M,K; double P;

	while(cin >> N >> M >> K >> P)
	{

		for(int i =0 ; i < MAXN;i++)
		{
			adj[i].clear();

			adj[i].erase(adj[i].begin(),adj[i].end());

			// printf("tamanho de adj[i] %d\n",adj[i].size());
		}

		for(int i = 0; i < M;i++)
		{
			int A,B;

			cin >> A >> B;

			adj[A].push_back(make_pair(B,0));	
			adj[B].push_back(make_pair(A,0));	

			// printf("Estou lend A , B = %d , %d\n",A,B);
		}

		int S;

		cin >> S;

		fill(enemy.begin(),enemy.end(),0);


		FOR(i,S)
		{
			int k;
			cin >> k;
			enemy[k]++;
			// cout << "Estou lendo enemy[k = " << k << "] = " << enemy[k] << END;
		}

		int init, dest;

		cin >> init >> dest;


		dijkstra(init);


		// cout << "The shortest distance from " << init;
		// cout << " to " << dest << " is " << dist[dest] << ".\n";
		// print_path(dest);

		if(!number_of_bullets(dest,K) || dist[dest] == INF)
		{
			// HEY
			printf("0.000\n");
		}else
		{
			printf("%.3lf\n",pow(P,dist[dest]));
		}


	}

	return 0;
}