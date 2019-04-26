#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int u,v, m, n,t;
vector<int > in, pre;
unordered_map <int ,int > mp;
void lca(int prel, int inl, int inr){
	if(inl> inr) return;
	int pp = mp[pre[prel]], pu = mp[u], pv =  mp[v];
	if(pu == pp){
		printf("%d is an ancestor of %d.\n", u, v);
	}
	else if(pv == pp){
		printf("%d is an ancestor of %d.\n", v, u);
	}else if(pv < pp && pu <pp){
		lca(prel +1, inl, pp-1);
	}else if(pv > pp && pu > pp){
		lca(prel + 1 + (pp-inl), pp+1, inr);
	}else {
		printf("LCA of %d and %d is %d.\n", u, v, pre[prel]);
	}
	
}
int main(){
	freopen("1151.txt", "r", stdin);
	cin>>m>>n;
	in.resize(n+1);
	pre.resize(n+1);
	for(int i =1; i<=n;++i){
		cin>>in[i];
		mp[in[i]]  = i;
	}
	for(int i =1; i<=n;++i){
		cin>>pre[i];
	}
	for(int i =0;i<m; ++i){
		cin>>u>>v;
		if(mp[u] == 0 && mp[v] ==0){
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}else if(mp[u] == 0){
			printf("ERROR: %d is not found.\n", u);
			continue;
		}
		else if(mp[v] == 0){
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		lca(1, 1, n);
		
	}
	return 0;
}
