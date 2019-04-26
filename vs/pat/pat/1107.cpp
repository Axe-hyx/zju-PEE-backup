#include "stdafx.h"

// 落到最后是对人的合并 
// 路径压缩 
// 每个课程对应头一个喜欢的人，作为集合的根
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn], n, k, t, c[maxn] = {-1}, cnt = 0;
int ans[maxn] = {0};
bool cmp(int a, int b){
	return a > b;
}
void init(){
	for(int i = 1; i<=n; ++i){
		father[i] = i;
	}
}
int findfather(int x){
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
	int fa = findfather(a);
	int fb = findfather(b);
	if(fa != fb)
		father[fa] = fb;
}
int main(){
	freopen("1107.txt", "r", stdin);
	cin>>n;
	init();
	for(int i=1; i<=n; ++i){
		cin>>k;
		getchar();
		for(int j =0; j<k; ++j){
			cin>>t;
			if(c[t] == 0)
				c[t] = i;
			Union(i, c[t]);
		}
	}
	for(int i = 1; i<=n; ++i){
		++ans[findfather(i)];
	}
	for(int i = 1; i<=n; ++i){
		if(ans[i] != 0)
			++cnt;
	}
	cout<<cnt<<endl;
	sort(ans+1, ans +n +1, cmp);
	for(int i = 1; i<=cnt; ++i){
		if(i!=1)
			cout<<" ";
		cout<<ans[i];
	}
	return 0;
}