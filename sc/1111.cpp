#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
const int maxn = 510;

// 1111 Ð´µÃºÃÐÁ¿à 
int d[maxn], t[maxn], n, m, w[maxn][maxn], ts[maxn][maxn], sn, en, pret[maxn], pred[maxn], we[maxn];
vector<int > G[maxn], ans, vdis, vtime;
bool vis[maxn] = {false};
int cnt =0;
void showd(int root){
	vdis.push_back(root);
	if(root== sn) return;
	showd(pred[root]);
}
void showt(int root){
	vtime.push_back(root);
	if(root == sn) return;
	showt(pret[root]);
}
int main(){
	freopen("1111.txt","r", stdin);
	cin>>n>>m;
	int a, b, c, f, e;
	fill(d, d+maxn, INF);
	fill(t, t+maxn, INF);
	fill(we, we +maxn , INF);
	
	fill(w[0], w[0] + maxn * maxn, INF);
	fill(ts[0], ts[0] + maxn* maxn, INF);
	for(int i=0; i<m; ++i){
		cin>>a>>b>>c>>f>>e;
		w[a][b] = f;
		ts[a][b] = e;
		if(c==0)
		{
			w[b][a] = f;
			ts[b][a] = e;
		}
	}
	cin>>sn>>en;
	
	d[sn] = 0;
	t[sn] = 0;
	for(int i=0; i<n; ++i){
		int u = -1, mins = INF;
		for(int j= 0; j<n; ++j){
			if(vis[j] == false && d[j] < mins){
				u = j;
				mins = d[j];
			}
		}
		if(u == -1) return 0;
		vis[u] = true;
		for(int v=0; v<n; ++v){
			if(vis[v]== false && w[u][v] != INF){
				if(d[u]+w[u][v] < d[v]){
					d[v] = d[u] + w[u][v];
					t[v] = t[u] + ts[u][v];
					pred[v] = u;
				}else if(d[u] + w[u][v] == d[v] && t[v] > t[u] + ts[u][v]){
					t[v] = t[u] + ts[u][v];
					pred[v] = u;
				}			
			}
		}
	}
	
	int len = d[en];
	fill(d, d+maxn, INF);
	memset(vis, 0, sizeof(vis));
	d[sn] = 0;
	we[sn] = 1;
	for(int i=0; i<n; ++i){
		int u = -1, mins = INF;
		for(int j= 0; j<n; ++j){
			if(vis[j] == false && d[j] < mins){
				u = j;
				mins = d[j];
			}
		}
		if(u == -1) return 0;
		vis[u] = true;
		//cout<<u<<we[u]<<endl;
		
		for(int v=0; v<n; ++v){
			if(vis[v] == false && ts[u][v] != INF){
				if(d[u] + ts[u][v] < d[v]){
					d[v] = d[u] + ts[u][v];
					we[v] = we[u] +1;
					pret[v]= u;
				}else if(d[u] + ts[u][v] == d[v] && we[u] + 1 < we[v]){
					we[v] = we[u] + 1;
					pret[v] = u;
				}
			}
		}
	}
	showd(en);
	showt(en);
	if(vdis != vtime){
		
		printf("Distance = %d: ", len);
		for(int j=vdis.size()-1; j>=0; --j){
			if(j!=vdis.size()-1)
				printf(" -> ");
			printf("%d", vdis[j]);
		}
		printf("\n");
		
		printf("Time = %d: ", d[en]);
		for(int j=vtime.size()-1; j>=0; --j){
			if(j!=vtime.size()-1)
				printf(" -> ");
			printf("%d", vtime[j]);
		}
		printf("\n");
	}else{
		printf("Distance = %d; Time = %d: ", len, d[en]);	
		for(int j=vtime.size()-1; j>=0; --j){
			if(j!=vtime.size()-1)
				printf(" -> ");
			printf("%d", vtime[j]);
		}
		printf("\n");
	}
	return 0;
} 
