#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct Node{
	int weight;
	vector<int> child;
}node[maxn];
int	n,m,s;
vector<int > temp;
void dfs(int root, int sum){
	if(root == NULL) return;
	sum += node[root].weight;
	
	temp.push_back(node[root].weight);
	if(sum == s){
		if(node[root].child.size() ==0){
			int sz = temp.size();
			for(int i=0; i < sz; ++i){
				if(i != 0)
					printf(" ");
				cout<<temp[i];
			}
			cout<<endl;
			temp.pop_back();
			return;
		}
		
	}
	for(int i=0; i<node[root].child.size(); ++i){
		dfs(node[root].child[i], sum);
	}
	temp.pop_back();

}
bool cmp (int a, int b){
	return node[a].weight > node[b].weight;
}
int main(){
	freopen("1053.txt", "r", stdin);
	cin>>n>>m>>s;
	for(int i =1; i <=n; ++i){
		cin>>node[i].weight;
	}
	for(int i =0; i <m; ++i){
		int id,	k,chi;
		cin>>id>>k;
		++id;
		for(int j = 0; j<k;++j){
			cin>>chi;
			node[id].child.push_back(chi+1);
		}
		sort(node[id].child.begin(), node[id].child.end() ,cmp);
	}
	dfs(1, 0);
	return 0;
}