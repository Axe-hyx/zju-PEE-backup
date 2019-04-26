#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int hashtable[10001];
int n,m,k;
vector<int> G[10001];


int main(){
	freopen("1154.txt", "r", stdin);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
	}	
	cin>>k;
	for(int i=0;i<k;++i){
		set<int> color;
		for(int j=0; j<n;++j){
			cin>>hashtable[j];
			color.insert(hashtable[j]);
		}
		
		bool flag = true;
		for(int u=0;u<n;++u){
			for(int v=0; v<G[u].size(); ++v){
				if(hashtable[u] == hashtable[G[u][v]])
					flag = false;
			}
		}
		if(flag)
			cout<<color.size()<<"-coloring"<<endl;
		else cout<<"No"<<endl;

	}
	return 0;
}