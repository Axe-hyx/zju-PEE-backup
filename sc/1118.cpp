#include <bits/stdc++.h>

using namespace std;
const int maxn = 10010;
int father[maxn], n,m, cnt[maxn];
bool vs[maxn] = {false};
int find(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[a]){
		int p = a;
		a = father[a];
		father[p] = x;
	}
	return x;
}
void Union(int a, int b){
	int fa = find(a);
	int fb = find(b);
	if(fa!=fb)
		father[fa] = fb;
}
int main(){
	freopen("1118.txt", "r", stdin);
	int pr,p;
	cin>>n;
	for(int i=0; i<maxn; ++i){
		father[i] = i;
	}
	for(int i=0; i<n; ++i){
		cin>>m>>pr;
		vs[pr] = true;
		for(int j =1; j<m; ++j){
			cin>>p;
			vs[p] = true;
			Union(p, pr);
		}
	}
	int numtree = 0, numbirds = 0;
	memset(cnt, 0, sizeof(cnt));
	
	for(int i=1; i<maxn; ++i){
		if(vs[i] == true){
			++cnt[find(i)];
		}
	}
	for(int i=1; i<maxn; ++i){
		if(vs[i] == true && find(i) ==i){
		
			++numtree;
			numbirds += cnt[i];
		}
		
		
	}
	printf("%d %d\n", numtree, numbirds);
	cin>>p;
	for(int i=0; i<p; ++i){
		int a, b;
		cin>>a>>b;
		if(find(a) != find(b)) {
			printf("No\n");
		}else printf("Yes\n");
	}
	return 0;
}
