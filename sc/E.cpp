#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
struct Node{
	int data, left, right;	
}tree[22];
int unb = 0, n;
int idx =1, hhp[22];
int lastlayer = 0;
bool compelete(int root){
	queue<int>qu;
	qu.push(root);
	int p = n;
	while(p){
		int sz = qu.size();
		for(int i =0; p && i<sz; ++i){
			int u = qu.front();
			qu.pop();
			if(u == -1 ) return false;
			hhp[idx++] = tree[u].data;
 			qu.push(tree[u].left);
			qu.push(tree[u].right);
			--p;
		}
		++lastlayer;
		
	}
	return true;
}
bool judge(int root, int &height){
	if(root == -1) {
		height = 0;
		return true;
	}
	int lh, rh;
	bool lb = judge(tree[root].left, lh);
	bool rb = judge(tree[root].right, rh);
	height= max(lh, rh) +1;
	bool isb = abs(lh-rh) <=1;
	if(!isb) {
		++unb;
		return false;
	}
	return isb && lb && rb;
	
}
bool vis[22] ={false};
int findroot(){
	for(int i =1; i<=n;++i){
		if(tree[i].left!=-1)
			vis[tree[i].left] = true;
		if(tree[i].right!=-1)
			vis[tree[i].right] = true;
	}
	for(int i=1; i<=n; ++i)
		if(vis[i] == false)
			return i;
	return -1;
}

int st = 0;
void adjustdown(int low, int high){
	int i = low, j = i * 2;
	while(j <= high){
		if(j+1 <= high && hhp[j+1]>hhp[j])
			++j;
		if(hhp[i] < hhp[j]){
			swap(hhp[i], hhp[j]);
			++st;
		 	i = j;
		 	j = j *2;
		}else break;
	}
}
void createheap(){
	for(int i = n /2; i>=1; --i){
		adjustdown(i,n);
	}
}
int main(){
	freopen("E.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int data;
		scanf("%d", &data);
		tree[i].data = data;
	}
	for(int i =1; i<=n; ++i){
		string a,b;
		cin>>a>>b;
		if(a[0] == '-')
			tree[i].left = -1;
		
		else tree[i].left = stoi(a);
		if(b[0] == '-')
			tree[i].right = -1;
		else tree[i].right = stoi(b);
		
	}
	int h = 0;
	int root = findroot();
	
	
	if(judge(root, h)){
		if(!compelete(root)){
			printf("NOT COMPLETE TREE!!!\n%d", lastlayer);
		}else{
			createheap();
			printf("OHHHHH HEAP!!!\n%d", st);
		}
		
	}else {
		printf("NOT AVL TREE!!!\n%d", unb);
	}
	return 0;
}
