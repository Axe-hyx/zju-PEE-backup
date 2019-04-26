#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff
const int maxn = 510;
int G[maxn][maxn], n,m,c1,c2, w[maxn], c[maxn], d[maxn], num[maxn];
bool vis[maxn] = {false};
using namespace std;
void dij(int s){
	fill(d, d+n, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));

	d[s] = 0;
	w[s] = c[s];
	num[s] = 1;

	for(int i =0; i<n; ++i){
		
		int u = -1, mins = INF;
		for(int j=0;j<n; ++j){
			if(vis[j] == false && d[j] < mins)
			{
				mins = d[j];
				u = j;
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v =0; v<n; ++v){
			if( vis[v] == false && G[u][v] != INF){
				if(d[v] > d[u] + G[u][v]){
					d[v] =d[u] + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + c[v];
				}else if(d[v] == d[u] + G[u][v]){
					if(w[v] < w[u] + c[v])
						w[v] = w[u] + c[v];
					num[v] += num[u];
				}
			} 
		}
	}
}

int main(){
	freopen("1003.txt", "r", stdin);
	cin>>n>>m>>c1>>c2;
	for(int i =0; i<n; ++i){
		cin>>c[i];
	}
	
	fill(G[0], G[0]+ maxn*maxn, INF);
	for(int i=0; i<m; ++i){
		int a, b, s;
		cin>>a>>b>>s;
		G[a][b] = s;
		G[b][a] = s;
	}

	dij(c1);
	cout<<num[c2]<<" "<<w[c2];
	return 0;
}
