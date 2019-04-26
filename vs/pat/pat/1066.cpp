#include "stdafx.h"

// 一共三处 *& insert L R
#include <iostream>
using namespace std;
int n;
struct Node{
	int data, height;
	Node *l, *r;
};

int getH(Node* root){
	if(root == NULL) return 0;
	return root->height;
}
int getF(Node *root){
	return getH(root->l) - getH(root->r);
}
void updateH(Node *root){
	root->height = max(getH(root->l), getH(root->r)) + 1;
}
void L(Node *&root){
	Node * temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void R(Node *&root){
	Node *temp = root->l;
	root->l = temp->r;
	temp->r = root;
	updateH(root);
	updateH(temp);
	root = temp;
}


void insert( Node*& root, int data){
	if(root == NULL){
		root = new Node;
		root->l = NULL;
		root->r = NULL;
		root->data = data;
		root->height = 1;
		return ;
	}else
		if(data < root->data){
			insert(root->l, data);
			updateH(root);
			if(getF(root) == 2){
				if(getF(root->l) == 1){
					R(root);
				}
				else if(getF(root->l) == -1){
					L(root->l);
					R(root);
				}
			}
			
		}
		else {
			insert(root->r, data);
			updateH(root);
			if(getF(root) == -2){
				if(getF(root->r) == 1){
					R(root->r);
					L(root);
				}
				else if(getF(root->r) == -1){
					L(root);
				}
			}
		}
}

int main(){
	freopen("1066.txt", "r", stdin);
	cin>>n;
	Node * root = NULL;
	for(int i =0; i<n; ++i){
		int t;
		cin>>t;
		insert(root, t);
	}
	cout<<root->data;
}