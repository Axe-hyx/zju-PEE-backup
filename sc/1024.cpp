#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct Node{
	vector<int>child;
	int data;
}tree[10010];
string ans;
int root[10010], father[10010];
bool isrot[10010]={false};
int m,n;
void init(){
	for(int i =1; i<=n; ++i){
		father[i] = i;
	}	
}
int findF(int x){
	int a = x;
	while(x!=father[x])
	{
		x = father[x];
	}
	while(a!=father[a]){
		int p = a;
		a = father[a];
		father[p] = x;
	}
	return x;
}
void Union(int a, int b){
	int fa = findF(a);
	int fb = findF(b);
	if(fa != fb) {
		if(fa < fb)
			father[fb] = fa;
		else father[fa] = fb;
	}
		
}

string removezero(string a){
	while(a.length()>1 && a.back()=='0')
		a.pop_back();
	return a;
}
string getsum(string a, string b){
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry= 0;
	int temp = 0;
	for(int i=0; i<a.length() || i< b.length() || carry; ++i){
		int ca = i<a.length()? (a[i] -'0' ): 0;
		int cb = i<b.length()? (b[i] -'0' ): 0;
		c += (ca + cb + carry ) % 10 +'0';
		carry = (ca + cb + carry)/10;
	}
	c = removezero(c);
	reverse(c.begin(), c.end());
	return c;
}
void dfs(int root,string s){
	if(tree[root].child.size() == 0){
		s+=tree[root].data+'0';
		ans = getsum(ans, s);
		return;
	}
	s+= tree[root].data +'0';
	for(int i=0; i<tree[root].child.size(); ++i)
		dfs(tree[root].child[i], s);
}
int main(){
	freopen("1024.txt", "r", stdin);
	cin>>n>>m;
	memset(isrot, 0, sizeof(isrot));
	for(int i=1; i<=n;++i){
		cin>>tree[i].data;
	}

	init();
	
	for(int i=0; i<m;++i){
		int a,b;
		cin>>a>>b;
		++a,++b;
		Union(b,a);
		tree[a].child.push_back(b);
	}
	for(int i =1; i<=n;++i){
		isrot[findF(i)] = true;
	}
	int cnt = 0;
	for(int i =1; i<=n;++i){
		if(isrot[i]) ++cnt;
	}
	cout<<cnt<<endl;
	int p = 0;
	
	
	for(int i =1; i<=n;++i){
		
		string s="";
		if(isrot[i]) {
			ans = "0";
			if(p!=0)
				cout<<" ";
			dfs(i, s);
			cout<<ans;
			++p;
			
		}
	
	}
	return 0;
}
