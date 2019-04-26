#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#define INF 0x3fffffff
const int maxn = 1e6 + 10;
using namespace std;
bool vis[maxn];
struct Node{
	int v;
	long long dis;
	Node(){
	
	}
	Node(int _v, long long _dis){
		v = _v;
		dis = _dis;
	}
};
vector<Node> adj1[maxn], adj2[maxn];
typedef pair<int, int> nodepair;
int n, m, p, k, target[maxn];

void dij(vector<Node> adj[], int d[]){
	fill(d, d + maxn, INF );
	
	
	priority_queue<nodepair, vector<nodepair>, greater<nodepair> > qu;
	d[0]= 0;
	qu.push(make_pair(0,0));
	while(!qu.empty()){
		int u = qu.top().second;
		int du = qu.top().first;
		qu.pop();
		cout<<u<<endl;
		for(int i=0; i<adj[u].size();++i){
			int v = adj[u][i].v, dis = adj[u][i].dis;
			if(d[v] > d[u] + dis)
				{
					d[v] = d[u]  + dis;
					qu.push(make_pair(d[v], 0));
				}
		}
	}
}

int main(){
	freopen("Notafraid.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &p, &k);
	return 1;
	for(int i=0; i<p; ++i){
		int ori;
		scanf("%d", &ori);
		adj1[0].push_back(Node{ori, 0});
		adj2[ori].push_back(Node{0, 0});
	}
	for(int i=0; i<k; ++i){
		scanf("%d", &target[i]);
	}
	for(int i=0; i<m; ++i){
		int u, v;
		long long w;
		scanf("%d %d %lld",&u, &v, &w);
		adj1[u].push_back(Node{v, w});
		adj2[v].push_back(Node{u, w});
	}
	int d1[maxn], d2[maxn];
	
	dij(adj1, d1);
	dij(adj2, d2);
}

