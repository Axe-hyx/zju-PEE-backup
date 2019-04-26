#include "stdafx.h"


// 并查集 吸收 最后isroot 统计时 再调用一次findf 进行路径压缩
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e4+10;
vector <int> G[maxn];
set<int> nodes, tem;
int n, father[maxn], ans = 0, maxl = -1;
bool isrot[maxn] = {false};
void dfs(int root, int level, int pre){
	int sz = G[root].size();
	if(level > maxl){
		maxl = level;
		nodes.clear();
		nodes.insert(root);
	}else if(level == maxl){
		nodes.insert(root);
	}
	++level;
	for(int i =0; i<sz; ++i){
		if(G[root][i] == pre)continue;
		dfs(G[root][i], level, root);
	}
}
void init(){
	for(int i=1; i<=n; ++i){
		father[i] = i;
	}
}
int findF(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){
		int p = a;
		a = father[a];
		father[p] = x;
	}
	return x;
}
void Union(int a, int b){
	int fa = findF(a);
	int fb = findF(b);
	if(fa != fb){
		father[fa] = fb;
	}
}

int main(){
	freopen("1021.txt", "r", stdin);
	cin>>n;
	init();
	for(int i =1; i<n; ++i){
		int a, b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	
	
	for(int i=1;i<=n; ++i){
		isrot[findF(i)] = true;;
	}
	for(int i=1;i<=n; ++i){
		if(isrot[i] == true) ++ans;
	}
	if(ans != 1 ){
			cout<<"Error: "<<ans<<" components"<<endl;
			return 0;
	}
	
	dfs(1, 1, -1);
	tem = nodes;
	dfs(*nodes.begin(), 1, -1);
	for(set<int >::iterator it =  tem.begin(); it!= tem.end(); ++it){
		nodes.insert(*it);
	}
	
	for(set<int >::iterator it =  nodes.begin(); it!= nodes.end(); ++it){
		cout<<*it<<endl;
	}
	return 0;
}