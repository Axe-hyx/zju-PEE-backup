#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int cp[maxn], rcp[maxn];
int main(){
	freopen("1121.txt", "r", stdin);
	int n,a,b;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		cp[a] = b;
		cp[b] = a;
	}
	set<int > gu;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a;
		if(gu.count(cp[a]) == 0){
			gu.insert(a);
		}else
			{
				gu.erase(cp[a]);
			}
	}
	printf("%d\n", gu.size());
	for(auto it= gu.begin(); it != gu.end(); ++it){
		if(it!=gu.begin())
			printf(" ");
		printf("%05d", *it);
	}
	return 0;
}
