#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> ans;
struct Node{
	int data;
	Node*l, *r;
};

void insert(Node *&root, int data){
	if(root == NULL){
		root = new Node;
		root->l= NULL;
		root->r= NULL;
		root->data=  data;
		return ;
	}
	if(data < root->data){
		insert(root->l, data);
	}else
		insert(root->r, data);
}
void preorder(Node *root, vector<int> &n){
	if(root == NULL) return ;
	n.push_back(root->data);
	preorder(root->l,n);
	preorder(root->r,n);
	
}
void postorder(Node *root){
	if(root == NULL) return;
	postorder(root->l);
	postorder(root->r);
	ans.push_back(root->data);
}
void levelorder(Node *root){
	queue<Node *> qu;
	qu.push(root);
	while(!qu.empty()){
		Node * t = qu.front();
		qu.pop();
		ans.push_back(t->data);
		if(t->l) qu.push(t->l);
		if(t->r) qu.push(t->r);
	}
}
int main(){
	freopen("1008.txt", "r", stdin);
	int n,t;
	cin>>n;
	Node *rl=NULL, *rr=NULL;
	vector<int > nl,nr;
	for(int i=0; i<n; ++i){
		cin>>t;
		insert(rl, t);
	}

	for(int i=0; i<n; ++i){
		cin>>t;
		insert(rr, t);
	}
	preorder(rl, nl);
	preorder(rr, nr);
	if(nl != nr) 
	{
		cout<<"NO"<<endl;
		
	}
	else cout<<"YES"<<endl;
	postorder(rl);

	for(int i=0; i<ans.size();++i){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	ans.clear();
	cout<<endl;
	levelorder(rl);
	
	for(int i=0; i<ans.size();++i){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	return 0;
} 
