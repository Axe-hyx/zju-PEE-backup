#include "stdafx.h"

// ios sync tie 开启之后 不要再用scanf
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<int, int> tb;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("1054.txt", "r", stdin);
	int m, n;
	
	cin>>m>>n; // scanf("%d%d", &m, &n);
	
	int t;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>t;
			if(tb.find(t)==tb.end()){
				tb[t] = 1;
			}else{
				tb[t]++;
			}
		}
	}
	int ans = 0;
	int max = 0;
	for(map<int, int >::iterator it = tb.begin(); it!=tb.end(); ++it){
		if(it->second > max){
			max = it->second;
			ans = it->first;
		}		
	}
	cout<<ans<<endl;
	return 0;

}
