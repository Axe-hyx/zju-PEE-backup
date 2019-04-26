#include "stdafx.h"

// 单一路径 pre 即可
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
const int maxn = 510;
int G[maxn][maxn],cost[maxn][maxn], c[maxn], d[maxn], n,m,sn,dn, pre[maxn];
bool vis[maxn] ={false};
void dij(int s){
	fill(d, d+n, INF);
	memset(c, 0, sizeof(c));
	d[s] = 0;
	c[s] = 0;
	for(int i=0; i<n;++i){
		int u =-1, mins = INF;
		for(int j=0; j<n; ++j){
			if(vis[j] == false && d[j] < mins){
				mins = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v=0; v<n; ++v){
			if(vis[v] == false && G[u][v] != INF){
				if(d[v] > d[u] + G[u][v]){
					pre[v] = u;
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
				}else if(d[v] == d[u] + G[u][v]){
					if(c[v] > c[u] + cost[u][v]){
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void dfs(int s){
	if(s == sn) {
		cout<<s<<" ";
		return;
	}
	dfs(pre[s]);
	cout<<s<<" ";
}
int main(){
	freopen("1030.txt", "r", stdin);
	fill(G[0], G[0] + maxn * maxn, INF);
	cin>>n>>m>>sn>>dn;
	for(int i=0; i<m; ++i){
		int ca,cb,cd,cc;
		cin>>ca>>cb>>cd>>cc;
		cost[ca][cb] = cc;
		cost[cb][ca] = cc;
		G[ca][cb] = cd;
		G[cb][ca] = cd;
	}
	dij(sn);
	dfs(dn);
	cout<<d[dn]<<" "<<c[dn];
}