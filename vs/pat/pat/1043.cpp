#include "stdafx.h"

//指针一定记得初始化 NULL pat 默认不置为NULL

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1010;
int n;
vector<int> ori, pre, mipre, post;
struct Node{
	int data;
	Node *l, *r;
};
using namespace std;

Node *newNode(int data){
	
	Node *root = new Node;
	root->l = NULL;
	root->r = NULL;
	root->data = data;
	return root;
}

void insert(Node *&root, int data){
	if(root == NULL){
		root = newNode(data);
	}else if(data < root->data){
		insert(root->l, data);
	}else 
		insert(root->r, data);
}
void preor(Node* root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preor(root->l, vi);
	preor(root->r, vi);
}
void preMirror(Node *root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preMirror(root->r, vi);
	preMirror(root->l, vi);
}

void postor(Node *root, vector<int> &vi){
	if(root == NULL) return;
	postor(root->l,vi);
	postor(root->r,vi);
	vi.push_back(root->data);
}
void postmior(Node *root, vector<int> &vi){
	if(root == NULL) return;
	postmior(root->r, vi);
	postmior(root->l, vi);
	vi.push_back(root->data);
}
int main(){
	freopen("1043.txt", "r", stdin);
	cin>>n;
	Node *root = NULL;
	for(int i =0; i<n; ++i){
		int t;
		cin>>t;
		ori.push_back(t);
		insert(root, t);
	}
	cout<<root->data;
	preor(root,pre);
	preMirror(root,mipre);
	return 1;
	if(pre  == ori){
		cout<<"YES"<<endl;
		postor(root, post);
		for(int i =0; i<post.size(); ++i){
			if(i!=0) cout<<" ";
			cout<<post[i];
		}
	}else if( mipre == ori){
		cout<<"YES"<<endl;
		postmior(root, post);
		for(int i =0; i<post.size(); ++i){
			if(i!=0) cout<<" ";
			cout<<post[i];
		}
	}else 
		cout<<"NO"<<endl;

	return 0;
}