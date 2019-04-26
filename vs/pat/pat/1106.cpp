#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cmath>

const int maxn = 1e5 + 10;
using namespace std;
int n;
double price, dd;
vector<int >G[maxn];
bool lef[maxn] = {false};
int he =  maxn, cnt =1;
void dfs(int root, int lev){
	if(root == NULL) return;
	
	if(!lef[root]){
		if(lev < he){
			he = lev;
			cnt = 1;
		}
		else if(lev == he)
			++cnt;
	}
	else{
		++lev;
		for(int i =0 ;i<G[root].size(); ++i){
			dfs(G[root][i], lev);
		}
	}
}
int main(){
	freopen("1106.txt", "r", stdin);
	cin>>n>>price>>dd;
	dd /=100;
	for(int i =1;i<=n;++i){
		int cnt,id;
		cin>>cnt;
		for(int j=0;j<cnt;++j){
			cin>>id;
			lef[i] = true;
			G[i].push_back(id+1);
		}
	}
	dfs(1, 0);

	printf("%.4lf %d", price * pow(1.0+dd, he),cnt);
	return 0;
}