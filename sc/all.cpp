#include <stack>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
stack<int > order;
const int maxn = 1e3 +10;
int n, indegre[maxn], ve[maxn], w[maxn][maxn], vl[maxn], we[maxn][maxn];
vector<int > G[maxn];
bool topolsort(){
	queue<int > qu;
	for(int i= 0; i<n; ++i){
		if(indegre[i] == 0)
			qu.push(i);
	}
	while(!qu.empty()){
		int u = qu.front();
		qu.pop();
		order.push(u);
		for(int i =0; i<G[u].size(); ++i){
			int v = G[u][i];
			--indegre[v];
			if(indegre[v] == 0)
				qu.push(v);
			if(ve[u] + w[u][v] > ve[v]){
				ve[v] = ve[u] + w[u][v];
			}
		}
	}
	if(order.size() == n) return true;
	else return false;
}


int criticalpath(){
	memset(ve , 0, sizeof(ve));
	if(topolsort() == false) return -1;

	fill(vl, vl+n, ve[n-1]);
	while(!order.empty()){
		int u = order.top();
		order.pop();
		for(int i =0; i<G[u].size(); ++i){
			int v = G[u][v], w = we[u][v];
			if(vl[u] > vl[v]-w){
				vl[u] = vl[v] - w;
			}
		}
	}
	for(int u =0; u<n; ++u){
		for(int i=0; i<G[u].size(); ++i){
			int v=  G[u][i], w = we[u][v];
			int e= ve[u]; int l = vl[v]  -w;
			
		}
	}
}

struct Node{
	int data, height;
	Node *l, *r;
};
int getHeight(Node *root){
	if(root==NULL) return 0;
	else return root->height;
}
void updateH(Node *root){
	root->height = max(getHeight(root->l), getHeight(root->r))	+1;
}

int getBF(Node *root){
	return getHeight(root->l) -getHeight(root->r);
}

void L(Node *&root){
	Node *temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateH(root);
	updateH(temp);
	root = temp;
}
void R(Node *&root){
	Node *temp = root->r;
	root->l = temp->r;
	temp->r = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void insert(Node *&root, int data){
	if(root ==NULL){
		root = new Node;
		root->l = NULL;
		root->r = NULL;
		root->data = data;
		root->height = 1;
	}else if(data <= root->data){
		insert(root->l, data);
		updateH(root);
		if(getBF(root) == 2){
			if(getBF(root->l) == 1){ // LL
				R(root);
			}else if(getBF(root->l) == -1) // LR
			{
				L(root->l);
				R(root);
			}
		}
	}else{
		insert(root->r, data);
		updateH(root);
		if(getBF(root->r) ==1) //RL
		{
			R(root->r);
			L(root);
		}
		else if(getBF(root->r) == -1) // RR
		{
			L(root);
		}
	}
}
int a[maxn];
void insertsort(){
	for(int i =2; i<=n; ++i){
		int j = i , t = a[i];
		while(j > 1 && a[j-1] > t){
			a[j] = a[j-1];
			--j;
		}
		a[j] = t;
	}
}
void merge(int A[], int l1, int r1, int l2, int r2){
	int i = l1, j = l2;
	int temp[maxn], index =0;
	while(i <= r1 && j<=r2){
		if(A[i] <= A[j]){
			temp[index++] = A[i];
		}else {
			temp[index++] = A[j];
		}
	}
	while(i<=r1) temp[index++] = A[i];
	while(j<=r2) temp[index++] = A[j];
	for(int i =0; i<index; ++i){
		A[l1 + i] = temp[i];
	}
}
int mergesort(int a[]){
	for(int step =2; step/2 <=n; step*=2){
		for(int i=0; i<=n; i+=step){
			int mid = i + step/2 -1;
			//sort (A, i, min(i+step -1, n));
			merge(a, i, mid, mid + 1, min(n, i + step -1));
		}
	}
}

int partipation(int A[], int left , int right ){
	int temp = A[left];
	while(left < right){
		while(left < right && A[right] > temp) -- right;
		A[left ] = A[right];
		while(left < right && A[left] < temp) ++left;
		A[right]  =A[left];
	}
	A[left] = temp;
	return left;
}
void quicksort(int A[], int left , int right){
	if(left < right ){
		int pos = partipation(A, left, right);
		quicksort(A, left, pos -1);
		quicksort(A, pos +1, right);
	}
}

int gcd(int a, int b){
	if(b== 0) return a;
	return gcd(b, a %b);
}
struct fra{
	int up, int down;
};
int main(){
	cout<<gcd(2,3);
	return 0;
}

