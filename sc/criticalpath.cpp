#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1e3 + 10;
vector<int> G[maxn];
int indegre[maxn], outdegre[maxn];
int vl[maxn], ve[maxn], e[maxn][maxn], l[maxn][maxn], w[maxn][maxn];
bool is[maxn][maxn] = {false};
int maxlen = -1; 
int n,m;
int st, se;
vector<int >temp, ans;
stack<int > topolorder;
int criticalpath(){
	queue<int > qu;
	
	st = n+1;
	se = n+2;
	memset(ve, 0, sizeof(ve));
	for(int i=1; i<=n; ++i){
		if(indegre[i] == 0){ 
			G[st].push_back(i);
			w[st][i] = 0;
			++indegre[i];
		}
		if(outdegre[i] == 0){
			G[i].push_back(se);
			w[i][se] = 0;
			++indegre[se];
		}
		
	}
	qu.push(st);
	n+=2;

	while(!qu.empty()){
		int  u = qu.front();
		qu.pop();
		topolorder.push(u);
		for(int i=0; i<G[u].size();++i){
			int v= G[u][i];
			indegre[v]--;
			if(indegre[v] == 0){
				qu.push(v);
			}
			if(ve[u] + w[u][v] > ve[v])
				ve[v] = ve[u] + w[u][v];
			maxlen = max(ve[v], maxlen);
		}
	}
		
	if(topolorder.size()!= n) return false;
	
	fill(vl, vl+n+1, maxlen); 
	while(!topolorder.empty()){
		int u = topolorder.top();
		topolorder.pop();
		for(int i =0; i<G[u].size();++i){
			int v = G[u][i];
			if(vl[u] > vl[v] - w[u][v]){
				vl[u] = vl[v] - w[u][v];
			}
			
		}
	}

	for(int u=1; u<=n; ++u){
		for(int j=0; j<G[u].size(); ++j){
			int v = G[u][j];
			e[u][v] = ve[u];
			l[u][v] = vl[v] - w[u][v];
			if(e[u][v] == l[u][v]){
				is[u][v] = true;
			}
		}
	}
	
}
void dfs(int u){
	temp.push_back(u);
	if(u==se) {
		temp.pop_back();
		for(int i=1; i<temp.size(); ++i){
			if(i!=1) printf("->");
			printf("%d", temp[i]);
		}
		printf("\n");
		return;
	}	
	for(int j =0; j<G[u].size(); ++j){
		int v = G[u][j];
		if (is[u][v])dfs(v);		
	}
	temp.pop_back();
}
int main(){
	freopen("topol.txt", "r", stdin);
	//freopen("topol.out", "w", stdout);
	scanf("%d %d", &n, &m);
	memset(outdegre, 0, sizeof(outdegre));
	memset(indegre, 0, sizeof(indegre));
	for(int i=0; i<m; ++i){
		int u, v, we;
		scanf("%d %d %d", &u, &v, &we);
		++indegre[v];
		++outdegre[u];
		G[u].push_back(v);
		w[u][v] = we;
	}
	
	if(criticalpath() == false) {
		printf("NO\n");
		return 0;
	}else
		printf("YES\n");
	int k;
	scanf("%d", &k);
	
	for(int i=1; i<=n; ++i){
		sort(G[i].begin(), G[i].end(), less<int>());
	}
	for(int i=0; i<k; ++i){
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", e[a][b], l[a][b]);
	}
	printf("%d\n", maxlen);
	
	
	dfs(st);
	return 0;
} 
