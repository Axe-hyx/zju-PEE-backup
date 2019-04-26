#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e4 +10;
int v[maxn][maxn];
bool vis[maxn];
int n,m, ban = -1;
int maxcnt =0;
void tra(int root){
	vis[root] = true;
	for(int i=1; i<=n; ++i){
		if(i != ban && v[root][i] == 1 && vis[i] == false){
			tra(i);
		}
	}
}
void dfs(){
	memset(vis, false, sizeof(vis));
	for(int i =1; i<=n;++i){
		if(vis[i] == false){
			++maxcnt;
			tra(i);
		}
	}
}
int main(){
	freopen("2.txt", "r", stdin);
	cin>>n>>m;
	memset(v, 0, sizeof(v));
	for(int i=0; i<m; ++i){
		int a,b;
		cin>>a>>b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	dfs();
	int t;
	cin>>t;
	for(int i=0;i<t; ++i){
		int cnt = 0;
		cin>>ban;
		memset(vis, false, sizeof(vis));
		for(int j =1; j<=n;++j){
			if(j != ban &&vis[j] == false){
				++cnt;
				tra(j);
			}
		}
		if(cnt > maxcnt)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
