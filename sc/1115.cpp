#include <iostream>
#include <cstring>
// 题设条件 左树less or equal to 
using namespace std;
int c[1010];
int maxn = -1;
struct Node{
	int data;
	Node *l, *r;
};
void dfs(Node *root , int dep){
	if(root == NULL) return;
	++c[dep];
	if(dep > maxn) maxn = dep;
	dfs(root->l, dep+1);
	dfs(root->r, dep+1);
	
}
void build(Node *&root, int data){
	if(root == NULL){
		root = new Node;
		root->l = NULL;
		root->r = NULL;
		root->data = data;
		return ;
	}else if(data < root->data){
		return build(root->l, data);
	}
	else return build(root->r, data);
}
int main(){
	int n;
	freopen("1115.txt", "r", stdin);
	cin>>n;
	Node *root = NULL;
	memset(c, 0, sizeof(c));
	for(int i=0; i<n; ++i){
		int t;
		cin>>t;
		build(root, t);
	}
	dfs(root, 1);
	printf("%d + %d = %d", c[maxn], c[maxn-1], c[maxn] + c[maxn-1]);
	return 0;
}
