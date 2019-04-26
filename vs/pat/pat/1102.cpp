#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 11;
int n, cnt;
struct Node{
	int left, right;
}tree[maxn];

bool rot[maxn] = {false};

void level(int rot){
	queue<int >qu;
	qu.push(rot);
	cnt= 0;
	while(!qu.empty()){
		int t= qu.front();
		qu.pop();
		if(cnt !=0) printf(" ");
		cout<<t;
		++cnt;
		if(tree[t].left !=-1) qu.push(tree[t].left);
		if(tree[t].right!=-1) qu.push(tree[t].right);
	}
}

void in(int rot){
	if(rot == -1) return;
	in(tree[rot].left);
	if(cnt !=0) printf(" ");
	cout<<rot;
	++cnt;
	in(tree[rot].right);
}
void post(int root){
	if(root == -1) return;
	swap(tree[root].left, tree[root].right);
	post(tree[root].left);
	post(tree[root].right);
}
int main(){
	freopen("1102.txt", "r", stdin);
	
	cin>>n;
	char le,ri;
	for(int i=0; i<n; ++i){
		scanf("%*c%c %c", &le, &ri);
		if(le!= '-'){
			tree[i].left = le - '0';
			rot[le-'0'] = true;
		}else 
			tree[i].left = -1;
		if(ri!= '-'){
			tree[i].right = ri- '0';
			rot[ri-'0'] = true;
		}
		else
			tree[i].right = -1;
	}
	int root =0;
	for(;root<n;++root){
		if(rot[root] == false)
			break;
	}
	//cout<<root<<endl;
	post(root);
	
	level(root);
	cout<<endl;
	cnt = 0;
	in(root);

	return 0;
}
