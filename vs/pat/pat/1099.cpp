#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
const int maxn = 110;
int num[maxn], pnum =0;
struct Node{
	int data, l, r;
}node[110];
vector<int> pos;

void inorder(int root){
	if(root == -1) return;
	inorder(node[root].l);
	node[root].data = num[pnum++];
	inorder(node[root].r);
}
void postorder(int root){
	if(root == -1) return;
	postorder(node[root].l);
	postorder(node[root].r);
	if(pnum--!=n)
		cout<<" ";
	cout<<node[root].data;
}
void bfs(int root){
	if(root == -1) return;
	queue<int> qu;
	qu.push(root);
	while(!qu.empty()){
		int t = qu.front();
		qu.pop();
		if(pnum--!=n)
			cout<<" ";
		cout<<node[t].data;
		if(node[t].l != -1) qu.push(node[t].l);
		if(node[t].r != -1) qu.push(node[t].r);
	}
}
int main(){
	freopen("1099.txt", "r", stdin);
	cin>>n;
	int a,b;
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		node[i].l = a;
		node[i].r = b;
	}
	for(int i=0; i<n; ++i){
		cin>>num[pnum++];
	}
	sort(num, num + pnum);
	pnum =0;
	inorder(0);
	
	
	bfs(0);


	
	return 0;
}