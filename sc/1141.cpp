#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define esp 1e-3
using namespace std;
const int maxn = 1e4 + 10;
int father[maxn], cnt[maxn], set[maxn], area[maxn], cntset[maxn], cntarea[maxn];
bool exist[maxn] = {false};
int n;

struct  fam{
	int id, num, aset, aarea;
	bool operator<(const fam &a) const{
		if(aarea != a.aarea) return  ((double)aarea/num - (double)a.aarea/a.num > esp);
		else return id < a.id;
	}
};
vector<fam> v;
void init(){
	for(int i=1; i<maxn; ++i){
		father[i] = i;
	}
}
int find(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[a]){
		int p = a;
		a =  father[a];
		father[p] = x;
	}
	return x;
}
void Union(int a, int b){
	int fa = find(a);
	int fb = find(b);
	if(fa<fb){
		father[fb] = fa;
	}else
		father[fa] = fb;
}
int main(){
	freopen("1141.txt", "r", stdin);
	cin>>n;
	int p, l,r;
	init();
	memset(set, 0, sizeof(set));
	memset(cnt, 0, sizeof(cnt));
	memset(area, 0, sizeof(area));
	for(int i =0; i<n; ++i){
		cin>>p>>l>>r;

		exist[p] = true;
		if(l != -1) {
			exist[l] = true;
			Union(p,l);
		}
		if(r !=-1){
			exist[r] = true;
			Union(p,r);
		}
		int cn;
		cin>>cn;
		for(int j=0; j<cn; ++j){
			cin>>l;
			Union(p, l);
			exist[l] = true;
		}
		cin>>set[p];
		cin>>area[p];
	}
	for(int i=0; i<maxn; ++i){
		if(exist[i] == true) {
			++cnt[find(i)];
			cntset[find(i)] += set[i];
			cntarea[find(i)] += area[i];
		}
	}
	int numfamily = 0;
	for(int i =0; i<maxn; ++i){
		if(exist[i] == true && cnt[i] !=0)
			++numfamily;
	}
	
	for(int i=0; i<maxn; ++i){
		if(exist[i] == true && cnt[i] !=0){
			v.push_back({i, cnt[i], cntset[i], cntarea[i] });
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", numfamily);
	for(int i =0; i<v.size(); ++i){
		printf("%04d %d %.3lf %.3lf\n", v[i].id, v[i].num, (double)v[i].aset/v[i].num, (double)v[i].aarea/v[i].num);
	}


	return 0;
}
