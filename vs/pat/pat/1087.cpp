#include "stdafx.h"

#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3fffffff
const int maxn = 220;
map<int, string> id2s;
map<string, int> s2id;
bool vis[maxn];
int G[maxn][maxn], weight[maxn]={0}, w[maxn], pre[maxn], pt[maxn], d[maxn], n, k, num[maxn], cnt =0;
void dij(int s){
	fill(d, d+maxn, INF);
	memset(w, 0, sizeof(w));
	memset(pre, 0, sizeof(pre));
	memset(pt, 0, sizeof(pt));
	memset(vis, false, sizeof(vis));
	d[s] = 0;
	w[s] = weight[s];
	pt[s] = 0;
	num[s] = 1;
	for(int i=0; i<n; ++i){
		int u = -1, mins = INF;
		for(int j = 0; j<n; ++j){
			if(vis[j] == false && d[j] < mins){
				mins = d[j];
				u = j;
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v= 0; v<n ; ++v){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v] = u;
					pt[v] = pt[u] +1;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}else if(d[u] + G[u][v] == d[v]){
					num[v] +=num[u];
					if(weight[v] + w[u] > w[v]){
						w[v] = weight[v] + w[u];
						pre[v] = u;
						pt[v] = pt[u] + 1;
					}else if(weight[v] + w[u] == w[v]){
						double pavg = 1.0 * (weight[v] + w[u]) / (pt[u]+1);
						double avg = 1.0 * w[v]/pt[v];
						if(pavg > avg){
							pre[v] = u;
							pt[v] = pt[u] + 1;
						}
					}	
				}
			}
		}
	}

}
void dfs(int s){
	if(s==0){
		cout<<id2s[s];
		return;
	}
	dfs(pre[s]);
	cout<<"->"<<id2s[s];

}
int main(){
	freopen("1087.txt", "r", stdin);
	string st;
	cin>>n>>k>>st;

	int t;
	fill(G[0], G[0] + maxn * maxn, INF);
	s2id[st] = cnt;
	id2s[cnt++] = st;
	for(int i=1;i<n; ++i){
		cin>>st>>t;
		
		s2id[st] = cnt;
		weight[cnt] = t;
		id2s[cnt++] = st;
	}
	for(int i = 0;i<k;++i){
		string a,b;
		int len;
		cin>>a>>b>>len;
		int ida = s2id[a];
		int idb = s2id[b];
		G[ida][idb] = len;
		G[idb][ida] = len;	
	}
	dij(0);

	int id = s2id["ROM"];
	cout<<num[id]<<" "<<d[id]<<" "<<w[id]<<" "<<(int)w[id]/pt[id]<<endl;
	dfs(id);

}