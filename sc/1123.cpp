#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Node{
	int data, height;
	Node *l , *r;
};
int getH(Node *root){
	if(root == NULL) return 0;
	else return root->height;
}
int getBF(Node *root){
	return getH(root->l) - getH(root->r);
}
void updateH(Node *root){
	root->height = max(getH(root->l), getH(root->r)) +1;
}

void R(Node *&root){
	Node *temp = root->l;
	root->l = temp->r;
	temp->r= root;
	updateH(root);
	updateH(temp);
	root = temp;
}
void L(Node *&root){
	Node * temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateH(root);
	updateH(temp);
	root = temp;
}
void insert(Node *&root, int data){
	if(root==NULL){
		root= new Node;
		root->l = NULL;
		root->r = NULL;
		root->height= 1;
		root->data = data;
		return ;
	}	else if(data < root->data){
		insert(root->l, data);
		updateH(root);
		if(getBF(root) == 2){
			if(getBF(root->l) == 1) //LL
			{
				R(root);
			}
			else if(getBF(root->l) == -1)  //LR
			{
				L(root->l);
				R(root);
			}
		}
	}
	else {
		insert(root->r, data);
		updateH(root);
		if(getBF(root) == -2){
			if(getBF(root->r)==1) {//RL
			{
				R(root->r);
				L(root);
			}
			}else if(getBF(root->r) ==-1) // RR
			{
				L(root);
			}
		}
	}
}
vector<int > ans;
void levorder(Node *root){
	queue<Node *> qu;
	qu.push(root);
	while(!qu.empty()){
		Node *q = qu.front();
		qu.pop();
		ans.push_back(q->data);
		if(q->l) qu.push(q->l);
		if(q->r) qu.push(q->r);
	}
}
int n;
bool check(Node *root){
	queue<Node *> qu;
	qu.push(root);
	bool flag = true;
	while(n){
		int sz = qu.size();
		for(int i =0; n &&i<sz; ++i){
			Node * t= qu.front();
			qu.pop();
			if(t==NULL) {
				flag= false;
				break;
			}
			qu.push(t->l);
			qu.push(t->r);
			n--;
		}
		if(flag == false) break;
	}
	if(n != 0) return false;
	return true;	
}
int main(){
	freopen("1123.txt", "r", stdin);
	int  a;
	cin>>n;
	Node *root = NULL;
	for(int i =0; i<n; ++i){
		cin>>a;
		insert(root, a);
	}
	levorder(root);
	for(int i=0; i<ans.size();++i){
		if(i!=0)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	printf("\n%s", check(root)?"YES" : "NO");
	return 0;
}
