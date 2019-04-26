#include "stdafx.h"

#include <iostream>
#include <queue>

//group 向上取整
//group 只晋级group个 当前轮次淘汰的为 group + 1名

using namespace std;

struct mouse{
	int weight;
	int r;
}mse[1010];
queue<int> qu;
int main(){
	freopen("1056.txt", "r", stdin);
	int p,g,t;
	cin>>p>>g;
	for(int i=0; i<p; ++i){
		cin>>mse[i].weight;
	}
	for(int i =0; i<p;++i){
		cin>>t;
		qu.push(t);
	}
	int i =1;
	int group;
	while(qu.size()!=1){
		int sz  = qu.size();
		if(sz  % g == 0) group = sz /g;
		else group = sz / g +1;
		for(int i =0; i<group; ++i){
			int k = qu.front();	
			for(int j =0; j<g; ++j){
				int pos = qu.front();
				if(i*g+j >=sz) break;
				if(mse[pos].weight> mse[k].weight){
					k = pos;
				}
				mse[pos].r = group + 1 ;
				qu.pop();
			}	
			qu.push(k);
		}
	}

	mse[qu.front()].r = 1;
	for(int i =0; i<p; ++i){
		if(i>0)
			cout<<" ";
		cout<<mse[i].r;
	}
	cout<<endl;
	return 0;
}