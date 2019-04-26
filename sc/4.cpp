#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define INF 0x3fffffff
const int maxn = 510;
vector<int> path;
int d[maxn]; 
bool vis[maxn];
int bal=-1, bar=-1;
int pre[maxn];
int dis[maxn][maxn], maxl = -1;
int n,m;
bool flag = true;
void dij(){
	fill(d, d+maxn, INF);	
		d[1] = 0;
		pre[1] = 1;
		memset(vis, false, sizeof(vis));
		for(int j =1; j<=n; ++j){
			int u = -1, mins= INF;
			for(int k= 1; k<=n; ++k){
				if(vis[k] == false && d[k] < mins){
					u = k;
					mins = d[k];
				}
			}
			if(u == -1) {
				maxl = INF;
				break;
			}
			vis[u] = true;
			for(int v=1; v<=n; ++v){
				if(vis[v] == false && dis[u][v] !=INF){
				 	if(u == bal && bar == v) continue;
				 	if(bar == u && bal == v) continue;
					if(d[u] + dis[u][v] < d[v]){
						d[v] = dis[u][v] + d[u];
						if (flag == true)pre[v] = u;
					}
				}
			}
		}
		
}
int main(){
//	freopen("4.txt", "r", stdin);
	cin>>n>>m;
	fill(dis[0], dis[0]+ maxn*maxn, INF);
	for(int i= 0; i<m; ++i){
		int a, b, c;
		cin>>a>>b>>c;
		dis[a][b]= c;
		dis[b][a]= c;
	}
	dij();
	flag = false;
	int v = n;
	while(v != pre[v]){
		bal =v; bar = pre[v];
		dij();
		maxl = max(maxl, d[n]);
		v = pre[v];
	}
	if(maxl == INF) 
		printf("It's a bug!!!\n");
	else printf("%d\n", maxl);
	return 0;
}
