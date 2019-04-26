#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;
const int maxn = 510;
int n,c,m,p, d[maxn], G[maxn][maxn], node[maxn], mneed = INF, mre = INF ;
vector<int> pre[maxn], temp, ans;
bool vis[maxn] = {false};
void dfs(int s){
	if(s == 0){
		temp.push_back(0);
		int need = 0,re=0;
		for(int i = temp.size()-1; i>=0; --i){
			if(node[temp[i]]>0){
				re +=node[temp[i]];
			}else{
				if(re >= abs(node[temp[i]]))
					re+=node[temp[i]];
				else
				{
					need += abs(node[temp[i]] + re);
					re =0;
				}
			}
				
		}
		if(mneed > need){
			mneed = need;
			mre = re;
			ans = temp;
		}else if(mneed == need && mre > re){
			mre = re;
			ans = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(int i =0; i<pre[s].size(); ++i){
		dfs(pre[s][i]);
	}
	temp.pop_back();
}
void dij(int s){
	fill(d, d+maxn, INF);
	d[s] = 0;

	for(int i=0;i<=n;++i){
		int u = -1, minf = INF;
		for(int j=0; j<=n; ++j){
			if(!vis[j] && d[j] < minf){
				minf = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
	
		for(int v=0; v<=n; ++v){
			if(!vis[v] && G[u][v] !=INF){
				if(d[v] > d[u] + G[u][v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[v] == d[u] + G[u][v]){
					pre[v].push_back(u);
				}
			}
		}
		
	}
}
int main(){
	freopen("1018.txt", "r", stdin);
	cin>>c>>n>>p>>m;
	for(int i=1; i<=n; ++i){
		cin>>node[i];
		node[i] -= c/2;
	}
	fill(G[0], G[0] + maxn * maxn, INF);
	for(int j = 0; j<m; ++j){
		int ta,tb,tc;
		cin>>ta>>tb>>tc;
		G[ta][tb] = tc;
		G[tb][ta] = tc;
	}
	dij(0);	
	dfs(p);
	cout<<mneed<<" ";
	for(int i = ans.size()-1; i>=0; --i){
		if(i !=ans.size()-1)
			cout<<"->";
		cout<<ans[i];
	}
	cout<<" "<<mre; 
}