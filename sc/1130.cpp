#include <iostream>
#include <cstring>
using namespace std;

bool isrot[22] = {true};
struct Node{
	char data[12];
	int l,r;
}tree[22];
string ans;
void dfs(int root){
	if(root == -1) return ;
	string s = tree[root].data;
	if(tree[root].l == -1 && tree[root].r == -1) {
		ans += s;
		return ;
	}
	ans += '(';
	dfs(tree[root].l);
	ans += s;
	dfs(tree[root].r);
	ans += ')';
}
int main(){
	freopen("1130.txt", "r", stdin);
	int n,a,b;
	cin>>n;
	memset(isrot,1 ,sizeof(isrot));
	for(int i=1; i<=n; ++i){
		scanf("%s %d %d", &tree[i].data, &tree[i].l, &tree[i].r);
		if(tree[i].l!=-1) isrot[tree[i].l] = false;
		if(tree[i].r!=-1) isrot[tree[i].r] = false;
	}
	int rot=1;
	while(rot<=n && isrot[rot]!=true) ++rot;
	
	dfs(rot);
	if(*ans.begin() == '(')	{
		ans.erase(ans.begin());
		ans.erase(ans.begin()+ans.size()-1);
	}
	
	cout<<ans;
	
	return 0;
} 
