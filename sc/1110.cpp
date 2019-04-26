#include <iostream>
#include <string>
#include <queue>

// 填充二叉树 最大节点编号 是否等于节点个数
// 注意判定条件 dfs写法
 
// bfs 写法 按照层遍历
// 原理 空节点占用位置 
using namespace std;
struct Node{
	int l,r;
}tree[100];
bool have[100] = {false};
int n,maxn =0, maxin = -1, last = -1;
void dfs(int root, int index){
	if(tree[root].l == -1 && tree[root].r == -1){

		if(index > maxin) {
			maxin = index;
			last = root;
		}
		return;
	}
	if(tree[root].l!=-1) dfs(tree[root].l, index *2);
	if(tree[root].r!=-1) dfs(tree[root].r, index *2 +1);
}
bool bfs(int root){
	queue<int > qu;
	qu.push(root);
	int p = n;
	
	while(p){
		int sz = qu.size();
		bool flag = true;
		for(int i=0; p && i<sz; ++i){
			int t= qu.front();
			qu.pop();
			if(t == -1)
			{
				flag  =false;
				break;
			}
			last = t;
			--p;
			qu.push(tree[t].l);
			qu.push(tree[t].r);
		}
		if(flag == false) break;
	}
	if(p!=0) return false;
	return true;
}
int main(){
	freopen("1110.txt", "r", stdin);
	cin>>n;
	string l,r;
	for(int i=0; i<n; ++i){
		cin>>l>>r;
		if(l[0] == '-'){
			tree[i].l = -1;
		}else{
			have[stoi(l)] = true;
			tree[i].l = stoi(l); 
		}
		if(r[0] == '-'){
			tree[i].r=  -1;
		}else{
			have[stoi(r)] = true;
			tree[i].r = stoi(r);
		}
	}
	int root =0;
	while(have[root]) ++root;
	
	
	if	(bfs(root) )cout<<"YES"<<" "<<last;
	else cout<<"NO"<<" "<<root;
	return 0;
}
