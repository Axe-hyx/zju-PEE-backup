#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
const int maxn = 101;
using namespace std;
vector<int> G[maxn];
int h[maxn];
int leaf[maxn] = {0};
int maxle = -1;
int n, m;
void dfs(int root, int lev){
	if(root == NULL) return;
	if(G[root].size()==0) ++leaf[lev];
	if(lev > maxle)
		maxle = lev;
	++lev;
	for(int i =0; i<G[root].size(); ++i){
		dfs(G[root][i], lev);
	}
}
void bfs(int root, int lev){
	if(root == NULL) return;
	queue<int >qu;
	qu.push(root);
	while(!qu.empty()){
		int t = qu.front();
		qu.pop();
		if(G[t].size()==0) ++leaf[h[t]];
		if(h[t]>maxle)
			maxle = h[t];
		for(int i =0;i<G[t].size(); ++i){
			h[G[t][i]] = h[t] + 1;
			qu.push(G[t][i]);
		}
	}
}
using namespace std;
int main(){
	freopen("1004.txt", "r", stdin);
	cin>>n>>m;
	
	for(int i= 0;i <m;++i){
		int id,k,t;
		cin>>id>>k;
		for(int j =0; j<k; ++j){
			cin>>t;
			G[id].push_back(t);
		}
	}
	//dfs(1, 1);
	h[1] = 1;
	bfs(1, 1);
	for(int i =1; i<=maxle; ++i){
		if(i!=1) cout<<" ";
		cout<<leaf[i];
	}

	
	return 0;
}