#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,cnt= 0;
bool v[10010];
vector<int>vex [10010];
int main(){
	freopen("1134.txt", "r", stdin);
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		int a,b;
		cin>>a>>b;
		vex[a].push_back(cnt);
		vex[b].push_back(cnt++);
	}
	int k;
	cin>>k;
	for(int i =0; i<k; ++i){
		int num ;
		cin>>num;
		memset(v, 0, sizeof(v));
		for(int j=0; j<num; ++j){
			int ve;
			cin>>ve;
			for(int i =0; i<vex[ve].size(); ++i){
				v[vex[ve][i]]= true;
			}
		}
		if(count(v, v+m, true) == m)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
