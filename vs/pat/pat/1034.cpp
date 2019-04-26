#include "stdafx.h"


// 通话记录1000 条 人数 2000 人
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2020;
int G[maxn][maxn]={0}, n, thredhold, mins, pnum = 0, node[maxn]= {0}, aid, bid;
bool vis[maxn] = {false};
map<string, int> name;
struct Gang{
	int head, pn;

}gang;
vector<Gang> Gs;
string id2name[maxn];

bool cmp(Gang a, Gang b){
	return id2name[a.head] < id2name[b.head];

}

void dfs(int i, int & totalnum, int &head, int &pn){
	vis[i] = true;
	++pn;
	if(node[head] < node[i])
		head = i;
	for(int j =0; j<pnum; ++j){
		if(G[i][j] == 0) continue;
		totalnum += G[i][j];
		G[i][j] = G[j][i] = 0;
		if( vis[j] == false)
			dfs(j, totalnum, head, pn);
	}
}
void DFStraveser(){
	for(int i =0; i<pnum; ++i){
		if(vis[i] == false){
			int totalnum =0, head = i, pn =0;
			dfs(i, totalnum,head, pn);
			if(totalnum > thredhold && pn > 2){
				struct Gang gang;
				gang.head = head;
				gang.pn =pn;
				Gs.push_back(gang);
			}
				
		}		
	}
}

int getid(string &s){
	if(name.count(s) == 0){
		id2name[pnum] = s;
		name[s] = pnum++;
		
	}
	return name[s];
}

int main(){
	freopen("1034.txt", "r", stdin);
	cin>>n>>thredhold;
	for(int i =0; i<n; ++i){
		string a,b;
		cin>>a>>b>>mins;
		aid = getid(a);
		bid = getid(b);
		
		node[aid] += mins;
		node[bid] += mins;
		G[aid][bid] += mins;
		G[bid][aid] += mins;
	}
	DFStraveser();
	sort(Gs.begin(), Gs.end(), cmp);
	cout<<Gs.size();
	for(int i=0; i<Gs.size();++i){
		cout<<endl;
		cout<<id2name[Gs[i].head]<<" "<<Gs[i].pn;
	}
	return 0;
}