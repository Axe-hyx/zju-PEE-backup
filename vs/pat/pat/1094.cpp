#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;

vector<int> G[maxn];
int hashtable[maxn] = {0};
int lev[maxn], maxlev = 1;
int n,m;

void dfs(int root, int level){
	if(root == NULL) return;
	++hashtable[level];
	if(hashtable[level]>hashtable[maxlev])
		maxlev = level;
	int sz = G[root].size();
	for(int i=0; i<sz; ++i){
		lev[ G[root][i] ] = lev[root] +1; 
		dfs(G[root][i],level+1);
	}
}
void bfs(int root){
	if(root ==NULL)return;
	queue<int> qu;
	qu.push(root);
	while(!qu.empty()){
		int t = qu.front();
		qu.pop();
		++hashtable[lev[t]];
		if(hashtable[lev[t]] > hashtable[maxlev]){
			maxlev = lev[t];
		}
		int sz = G[t].size();
		for(int i =0; i<sz; ++i){
			lev[G[t][i]] = lev[t] +1; 
			qu.push(G[t][i]);
		}
	}
}
int main(){
	freopen("1094.txt", "r", stdin);
	cin>>n>>m;
	for(int i =0; i<m;++i){
		int id, k, t;
		cin>>id>>k;
		for(int j =0; j<k; ++j){
			cin>>t;
			G[id].push_back(t);
		}
	}
	//lev[1] = 1;
	//bfs(1);
	dfs(1, 1);
	cout<<hashtable[maxlev]<<" "<<maxlev;
	return 0;
}