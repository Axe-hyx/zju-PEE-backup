#include <iostream>
#include <vector>
// �������һ�ڵ㻮�� �޷�ȷ���Ƿ�Ψһ ͨ������ǰһ�ڵ㻮�� ���������Ƿ��нڵ��ж� 
using namespace std;
int n, pre[31], in[31];
vector<int > ans;
struct Node{
	Node *l, *r;
	int data;
};
bool flag = true;
Node *build(int pre[], int post[], int prel, int prer, int postl, int postr){
	Node *root = new Node;
	root->data  = pre[prel];
	root->l = NULL;
	root->r = NULL;
	if(prel == prer) return root;
	int i = prel+1;
	while(i <= prer && pre[i]!= post[postr -1]) ++i;
	if(i- prel > 1) // ���������޽ڵ� �嵽�ұ� 
		root->l = build(pre, post, prel+1, i-1, postl, postl + (i-prel -1) -1);
	else flag = false;
	root ->r = build(pre, post , i,  prer, postl + (i-prel -1), postr-1);
	return root;
}
Node *build2(int pre[], int post[], int prel, int prer, int postl, int postr){
	if(prel > prer) return NULL;
	Node *root = new Node;
	root ->data = pre[prel];
	root ->l = NULL;
	root ->r = NULL;
	if(prel == prer) return root;
	int i = postl;
	while(i<=postr && post[i]!= pre[prel+1]) ++i;
	
	root->l = build(pre, post, prel +1, prel +1 + i - postl, postl, i);
	root->r = build(pre, post, prel +2 + i -postl, prer, i+1, postr-1);
	return root;
}
void inorder(Node *root){
	if(root == NULL) return ;
	inorder(root->l);
	ans.push_back(root->data);
	inorder(root->r);
}
int main(){
	freopen("1119.txt", "r", stdin);
	int n;
	cin>>n;
	Node *root = NULL;
	for(int i =0; i<n; ++i){
		cin>>pre[i];
	}
	for(int i =0; i<n; ++i){
		cin>>in[i];
	}
	root = build(pre , in, 0, n-1, 0,n -1);
	
	printf("%s\n", flag?"Yes":"No");
	inorder(root);
	for(int i=0; i<ans.size(); ++i){
		if(i!=0) 
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
} 
