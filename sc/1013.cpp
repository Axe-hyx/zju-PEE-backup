#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int > ans;
struct Tree{
	int data;
	Tree *l, *r;
};
Tree* build(int lev[], int in[],int ll, int lr, int inl, int inr){
	
	if(inl > inr) return NULL;
	Tree *root = (Tree *)malloc(sizeof(Tree));
	vector<int> left, right;
	unordered_set<int> st;
	
	root->data = lev[ll];

	int idx = -1;
	for(idx = inl; idx<=inr && in[idx] != lev[ll]; ++idx);
	
	for(int i =inl; i<idx; ++i)
		st.insert(in[i]);
	for(int i =ll+1; i<=lr; ++i){
		if(st.count(lev[i])){
			left.push_back(lev[i]);
		}else 
			right.push_back(lev[i]);
	}
	
	int i = ll+1;
	int sz = left.size();
	for(int pos = 0;pos<left.size(); ++pos){
		lev[i++] = left[pos];
	}
	for(int pos = 0;pos<right.size(); ++pos){
		lev[i++] = right[pos];
	}
	root->l = build(lev, in, ll+1, ll+sz,inl, idx-1);
	root->r = build(lev, in, ll+sz+1,lr,idx+1, inr);
	return root;	
}
int getheight(Tree *root){
	if(root == NULL) return 0;
	return max(getheight(root->l),getheight(root->r)) +1;
}
void preorder(Tree *root){
	if(root == NULL) return;
	ans.push_back(root->data);
	preorder(root->l);
	preorder(root->r);
}
void postorder(Tree *root){
	if(root == NULL) return;
	postorder(root->l);
	postorder(root->r);
	ans.push_back(root->data);
}
int maxr = 0;
void ruld(Tree *root, int len){
	if(root == NULL) return;
	if(len> maxr) maxr = len;
	ruld(root->l, len);
	ruld(root->r, len +1);
}

int leftmin = 0, rightmax = -1;
void tra(Tree *root, int d){
	if(root == NULL) return;
	if(d< leftmin) leftmin = d;
	if(d > rightmax) rightmax = d;
	tra(root->l, d-1);
	tra(root->r, d+1);
}
int main(){
	freopen("1013.in",  "r", stdin);
	int a[31], b[31];
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}

	for(int i=0; i<n; ++i){
		cin>>b[i];
	}	
	Tree *root = build(a, b, 0, n-1, 0, n-1);
	
	preorder(root);
	for(int i=0; i<ans.size(); ++i){
		if(i!= 0)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	ans.clear();
	postorder(root);
	for(int i=0; i<ans.size(); ++i){
		if(i!= 0)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	cout<<getheight(root)<<endl;
	ruld(root, 1);
	cout<<maxr<<endl;
	tra(root, 0);
	cout<<(rightmax +1 - leftmin)<<endl;

	return 0;
}
