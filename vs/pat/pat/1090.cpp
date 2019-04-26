#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 10;
int n, maxlev = 0;
double price, dd;
int hashtable[maxn] = {0};
vector<int> G[maxn];
void dfs(int root, int level){
	if(root == NULL) return;
	++hashtable[level];
	if(level > maxlev)
		maxlev = level;
	++level;
	for(int i=0; i<G[root].size(); ++i){
		dfs(G[root][i], level);
	}
}

int main(){
	freopen("1090.txt", "r", stdin);
	cin>>n;	
	cin>>price>>dd;
	dd /=100;
	int root;

	for(int i =1; i<=n; ++i){
		int id;
		cin>>id;
		++id;
		if(id!=0)
			G[id].push_back(i);
		else
			root = i;
	}
	dfs(root, 0);
	printf("%.2lf %d", price * pow(1.0 + dd, maxlev), hashtable[maxlev]);

}