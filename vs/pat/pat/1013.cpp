#include "stdafx.h"


// ø® ‰»Î
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
int n,m,k,idx;
vector<int >G[maxn];
bool vis[maxn] = {false};
	
void dfs(int r){
	if(r == idx) return;
	vis[r] = true;
	for(int i=0; i<G[r].size(); ++i){
		if(vis[G[r][i]]== false)
		dfs(G[r][i]);
	}
}
void dfstravese(){
	int cnt =0;
	memset(vis,0, sizeof(vis));
	for(int i =1; i<=n; ++i){
		if(idx != i &&vis[i] == false){
			++cnt;
			dfs(i);
		}
	}
	cout<<cnt-1<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("1013.txt", "r", stdin);
	cin>>n>>m>>k;
	for(int i=0; i<m; ++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i =0; i<k; ++i){
		cin>>idx;
		dfstravese();
		
	}

	return 0;
}