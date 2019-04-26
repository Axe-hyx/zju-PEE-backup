#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 1010;
bool vis[maxn][maxn];
vector<pair<int ,int>> v;

int main(){
	//freopen("C.txt", "r", stdin);
	int n,m;
	cin>>n>>m;
	for(int i =0; i<m; ++i){
		int l, r;
		cin>>l>>r;
		v.push_back({l, r});
	}
	int ca;
	cin>>ca;
	
	for(int i=0; i<ca; ++i){
		int num;
		cin>>num;
		memset(vis, false, sizeof(vis));
		bool flag = true;
		set<int>st ;
		for(int j=0; j<num; ++j){
			int l, r;
			cin>>l>>r;
			if(st.count(l) == 0)
				st.insert(l);
			else flag = false;
			if(st.count(r) == 0)
				st.insert(r);
			else flag = false;
			vis[l][r] = true;
			vis[r][l] = true;
		}
		if(flag == false){
			cout<<"Not a Matching\n";
			continue;
		}
		bool max = true;
		for(int i=0; i<v.size(); ++i){
			int l = v[i].first;
			int r = v[i].second;
			if(vis[l][r] == true || vis[r][l] == true) continue;
			if(st.count( l) == 0 && st.count(r) == 0) max = false;
		}
		if(max ) cout<<"Yes\n";
		else cout<<"Not Maximal\n";
		
	}	
	return 0;
}
