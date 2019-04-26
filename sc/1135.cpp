#include <iostream>
#include <algorithm>
// 给定bst先序 即插入顺序 
using namespace std;
bool cmp(int a, int b){
	return abs(a) < abs(b);
}
int pre[31],in[31];
struct Node{
	int data;
	Node *l, *r;
};
void build(Node *&root, int data){
	if(root == NULL)
	{
		root = new Node;
		root->l = NULL;
		root->r = NULL;
		root->data = data;
		return;
	}else if(abs(data) < abs(root->data))
	{
		build(root->l,data);
	}
	else build(root->r, data);
}
bool judge1(Node *root){
	if(root == NULL ) return true;
	if(root->data < 0){
		if((root->l != NULL && root->l->data<0 )||(root->r!=NULL && root->r->data <0) )	
			return false;
	}
	bool l = judge1(root->l);
	bool r = judge1(root->r);
	return l && r;
}
int getheight(Node *root){
	if(root==NULL) return 0;
	int l = getheight(root->l);
	int r = getheight(root->r);
	return root->data > 0 ? max(l, r) + 1 : max(l,r);
	
}
bool judge2(Node *root){
	if(root == NULL) return true;
	int l = getheight(root->l);
	int r = getheight(root->r);
	if(l != r) return false;
	else return judge2(root->l) && judge2(root->r);
}
void preorder(Node *root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->l);
	preorder(root->r);
}
int main(){
	freopen("1135.txt","r", stdin);
	int k;
	cin>>k;
	for(int i=0; i<k; ++i){
		int n,t;
		Node *root = NULL;
		cin>>n;
		for(int j=0; j<n; ++j){
			cin>>t;
			build(root,t);
		}
		if(root->data < 0 || judge1(root)== false || judge2(root)== false)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}
