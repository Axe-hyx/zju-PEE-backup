#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
// 找准 编译是否通过 从来没提交的区别
struct user{
	int all, perfect;
	bool flag;
	int id;
	int sco[6];
}usr[10010];

int cc[6];
bool cmp(user a, user b){
	if(a.all != b.all ) return a.all > b.all;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;

}

int n;
using namespace std;

void init(){
	for(int i=1; i<=n; ++i){
		memset(&usr[i],0 ,sizeof(usr[i]));
		usr[i].id = i;
 		memset(usr[i].sco, -1, sizeof(usr[i].sco));
	}
}
int main(){
	freopen("1075.txt", "r", stdin);
	int k, m;
	cin>>n>>k>>m;
	for(int i=1; i<=k; ++i){
		cin>>cc[i];
	}
	init();
	for(int i=0; i<m; ++i){
		int id, pid, ss;
		cin>>id>>pid>>ss;
		if(ss == -1 && usr[id].sco[pid] == -1) {
			usr[id].sco[pid] = 0;
			continue;
		}
		usr[id].flag = true;
		if(ss == cc[pid] && usr[id].sco[pid] < ss){
			++usr[id].perfect;
		}
		if(usr[id].sco[pid] < ss)
			usr[id].sco[pid] = ss;
			

	}
	for(int i =1; i<=n; ++i){
		for(int j = 1; j<=k; ++j){
			if(usr[i].sco[j]!=-1)
				usr[i].all += usr[i].sco[j];
		}
	}
	sort(usr+1, usr+n+1,cmp);
	
	int r = 1;
	for(int i = 1;i<=n;++i){
		if(i>1 && usr[i].all != usr[i-1].all) { 
			r = i;
		}
		if(!usr[i].flag) break;
		printf("%d %05d %d", r, usr[i].id, usr[i].all);
		for(int j = 1; j<=k; ++j){
			
			if(usr[i].sco[j]!=-1)
				printf(" %d", usr[i].sco[j]);
			else printf(" -");
		}
		cout<<endl;
	}
	return 0;
}