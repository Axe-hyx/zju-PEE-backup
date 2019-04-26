#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node{
	int data, layer;
	int l, r;
}tree[21];
int n;
int cnt= 0;
void adjustdown(int l, int r){
	int i = l, j = i * 2;
	while(j<=r){
		if(j+1 <= r && tree[j+1].data > tree[j].data)
			++j;
		if(tree[j].data > tree[i].data){
			++cnt;
			int t = tree[i].data;
			tree[i].data = tree[j].data;
			tree[j].data = t;
			i = j;
			j = j * 2;
		}else 
			break;
		
		
	}
	
}
void adjust(){
	
	for(int i=n/2; i>=1; --i){
		adjustdown(i, n);
	}
}
int layer = 0;
bool judgeBST(int root){
	queue<int>qu;
	qu.push(root);
	int p = n;
	while(p){	
		int sz = qu.size();
		for(int i=0; p && i<sz; ++i){
			int t = qu.front();
			qu.pop();
			if(t == -1 ) return false;
			--p;
			Node &f = tree[t];
			qu.push(f.l);
			qu.push(f.r);
		} 
		++layer;
	}
	
	return true;
}
int judgeAVL( int root){
	if(root == -1)	return 0;
	int l = judgeAVL(tree[root].l);
	int r = judgeAVL(tree[root].r);
	if(abs(l-r) > 1) ++cnt;
	return max (l, r) +1;
	
}
int main(){
	freopen("1016.txt", "r", stdin);
	cin>>n;
	memset(tree, -1, sizeof(tree));
	for(int i=1; i<=n; ++i){
		cin>>tree[i].data;
	}
	for(int i=1;i<=n;++i){
		int a,b;
		char ca[2],cb[2];
		scanf("%s %s", ca, cb);
		if(ca[0] == '-'){
			a= -1;
		}
		else sscanf(ca, "%d", &a);
		if(cb[0] == '-')
			b= -1;
		else sscanf(cb, "%d", &b);
		tree[i].l = a;
		tree[i].r = b;
	}
	judgeAVL(1);
	if(cnt!=0){
		cout<<"NOT AVL TREE!!!"<<endl;
		cout<<cnt<<endl;
		return 0;
	}
	
	if(judgeBST(1)== false){
		cout<<"NOT COMPLETE TREE!!!"<<endl;
		cout<<layer<<endl;
		return 0;
	}
	cnt = 0;
	adjust();
	cout<<"OHHHHH HEAP!!!"<<endl;
	cout<<cnt;
	return 0;
}
