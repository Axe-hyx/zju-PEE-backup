#include "stdafx.h"

#include <iostream>
#include <stack>
#include <cstring>
#include <string>
int n, pnum = 0, inum = 0, fnum = 0;
int in[31], fr[31], sta[31];
using namespace std;

struct Node{
	int data;
	Node *l, *r;
};

Node * newnode(int data){
	Node *root = (Node*)malloc(sizeof(Node));
	root->data = data;
	root->l = NULL;
	root->r = NULL;
	return root;
}
Node *create(int frl, int frr, int inl, int inr){
	if(frl > frr) return NULL;
	int t = fr[frl];
	Node *r = newnode(t);
	int i =inl;
	for(;i<=inr;++i){
		if(in[i] == t)break;
	}
	int len = i -inl;
	r->l = create(frl+1, frl + len, inl, i-1);
	r->r = create(frl + len + 1, frr, i+1, inr);
	return r;
}
int cnt =0;
void post(Node * root){
	if(root == NULL) return;
	post(root->l);
	post(root->r);
	++cnt;
	if(cnt != 1)
		printf(" ");
	printf("%d", root->data);
}

int main(){
	freopen("1086.txt", "r", stdin);
	int n, num;
	cin>>n;
	char ord[5];
	for(int i=0; i<n * 2; ++i){
		scanf("%s %d", &ord, &num);
		if(!strcmp(ord, "Push")) {
			sta[pnum++] = num;
			fr[fnum++] = num;
		}
		else{
			in[inum++] = sta[--pnum];
		}
	}
	Node * r = create(0, n-1, 0, n-1);
	

	post(r);
	//cout<<cnt<<endl;
	
	return 0;
}