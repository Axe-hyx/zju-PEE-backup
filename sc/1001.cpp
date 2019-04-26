#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
	int data;
	Node *l, *r;
};
void insert(Node *& root, int data){
	if(root == NULL){
		root = new Node;
		root->l = NULL;
		root->r = NULL;
		root->data  = data;
		return ;
	}
	if(data < root->data ){
		insert(root->l, data);
	}else
		insert(root->r, data);
}
void bfs(Node *root){
	queue<Node *> qu;
	qu.push(root);
	vector<int > ans;
	while(!qu.empty()){
		Node *t = qu.front();
		qu.pop();
		ans.push_back(t->data);
		if(t->l) qu.push(t->l);
		if(t->r) qu.push(t->r);
	}
	for(int i=0; i<ans.size(); ++i){
		if(i!=0)cout<<" ";
		cout<<ans[i];
	}

}
int main(){
	freopen("in", "r", stdin);
	int n, data;
	cin>>n;
	Node*root = NULL;
	for(int i =0; i<n; ++i){
		cin>>data;
		insert(root, data);
	}
	bfs(root);
	return 0;
}
