#include "stdafx.h"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
double price, dd;
const int maxn = 1e5 +10;
struct supplier{
	int w;
	vector<int >child;
}sup[maxn];
double ans =0.0;
void dfs(int root, int level){
	if(root == NULL) return;
	
	if(sup[root].child.size() == 0){
		ans += sup[root].w* price * pow(1.0 + dd, level);
		return;
	}
	++level;
	for(int i = 0;i<sup[root].child.size(); ++i){
		dfs(sup[root].child[i], level);
	}
}
int main(){
	freopen("1079.txt", "r", stdin);
	cin>>n>>price>>dd;
	dd/=100;
	for(int i =1;i<=n;++i){
		int k,id;
		cin>>k;
		if(k!=0)
			for(int j=0; j<k; ++j){
				cin>>id;
				sup[i].child.push_back(id+1);
			}
		else{
			int we;
			cin>>we;
			sup[i].w = we;
		}
			
	}
	dfs(1, 0);
	printf("%.1lf", ans);
	return 0;
}