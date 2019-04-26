#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int > ans;
bool ismin = true, ismax = true;
int n=0, node[1010];
void dfs(int root){
	if(root * 2 >n){
		ans.push_back(root);
		for(int i =0; i<ans.size();++i){
			if(i!=0)
				cout<<" ";
			cout<<node[ans[i]];
		}
		cout<<endl;
		ans.pop_back();
		return ;
	}
	ans.push_back(root);
	if(root * 2 +1 <= n)
		dfs(root * 2 +1);
	if(root *2 <=n)
		dfs(root *2);
	ans.pop_back();
}

int main(){
	freopen("1155.txt", "r", stdin);
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>node[i];
	}
	dfs(1);
	for(int i=2;i<=n;++i){
		if(node[i/2] < node[i]) ismax = false;
		if(node[i/2] > node[i]) ismin = false;
	}
	if(ismax)
		cout<<"Max Heap";
	else 
		printf("%s", ismin==true? "Min Heap" : "Not Heap");
	
	return 0;
}