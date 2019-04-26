#include "stdafx.h"


// D �ڽӱ�洢 vis����ͳ�� ÿ������ǰ�����vis
// dfs ����������ʽ ��ǰ���˾��� ��ǰ����ʹ�÷��ʼ����� �ж�����Ϊ||
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 0x3fffffff
const int maxn  = 1e4 + 10;
using namespace std;
vector <int> adj[maxn];
int n, l,cnt= 0;
bool vis[maxn] = {false}, per[maxn] = {false};
int layer[maxn] = {INF}; 
struct Node{
	int layer, id;
};
void dfs(int root, int ler){
	vis[root] = true;
	per[root] = true;
	layer[root] = ler;
	if(l != ler){
		for(int i= 0; i< adj[root].size(); ++i){
			if(!vis[adj[root][i]] || ler + 1 < layer[adj[root][i]])
				dfs(adj[root][i], ler+1);
		}
		
	}
}
void bfs(int root){
	queue<Node> qu;
	struct Node node;
	node.layer= 0;   
	node.id = root;
	vis[root] = true;
	qu.push(node);
	while(!qu.empty()){
		int t = qu.front().id, ler = qu.front().layer;
		qu.pop();
		for(int i =0;i<adj[t].size(); ++i){
			struct Node f;
			f.id = adj[t][i];
			f.layer = ler +1;
			if(!vis[adj[t][i]] && ler < l){
				vis[adj[t][i]] = true;		
				++cnt;
				qu.push(f);
			}
		}
		
	}
}
int main(){
	freopen("1076.txt", "r", stdin);
	cin>>n>>l;
	for(int i=1; i<=n; ++i){
		int k,t;
		cin>>k;
		for(int j=0; j<k; ++j){
			cin>>t;
			adj[t].push_back(i);
			
		}
	}
	int t,id;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>id;
		memset(vis, 0, sizeof(vis));
		memset(per, 0, sizeof(per));
		fill(layer, layer+n, 7);
		cnt = 0;
		//bfs(id);
		dfs(id, 0);
		cout<<count(per+1,per+n+1, true )-1<<endl;
	}
	return 0;
}