#include "stdafx.h"

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>ans;
int n, in[31], post[31];

struct Node{
	int data;
	Node *l,*r;
};


Node *node(int data){
	Node * root = (Node *) malloc(sizeof(Node));
	root->data = data;
	root->l = NULL;
	root->r = NULL;
	return root;
}

void bfs(Node *root){
	if(root == NULL) return ;
	queue<Node*> qu;
	qu.push(root);
	while(!qu.empty()){
		
		Node *q = qu.front();
		qu.pop();
		ans.push_back(q->data);
		if(q->l) qu.push(q->l);
		if(q->r) qu.push(q->r);
	}
}

Node *create(int inl, int inr, int posl, int posr){
	if(posl > posr) return NULL;
	int t = post[posr];
	Node *root = node(t);
	int i;
	for(i =inl; i<=inr; ++i)
		if(in[i] == t) break;
	int len = i - inl;
	root->l = create(inl, i-1, posl, posl +len -1);
	root->r = create(i+1, inr, posl + len, posr -1);
	return root;
}
int main(){
	freopen("1020.txt", "r", stdin);
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>post[i];
	}
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	Node *t = create(0,n-1, 0, n-1);
	
	bfs(t);
	for(int i=0; i<n; ++i){
		if(i!=0)
			printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}