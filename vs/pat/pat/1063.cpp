#include "stdafx.h"

#include <cstdio>
#include <set>

using namespace std;
#define maxn 51
set<int> st[maxn];

int main(){
	freopen("1063.txt", "r", stdin);
	int sn;
	scanf("%d", &sn);
	int nu,n;
	for(int i =1; i<=sn; ++i){
		scanf("%d", &nu);
		for(int j=0; j<nu; ++j){
			scanf("%d",&n);
			st[i].insert(n);
		}
	}
	int cnt, all;
	int qn;
	scanf("%d", &qn);
	int s1, s2;
	for(int i=0; i< qn; ++i){
		cnt = 0;
		all = 0;
		scanf("%d%d", &s1, &s2);
		all += st[s2].size();
		for(set<int>::iterator it = st[s1].begin(); it!=st[s1].end(); ++it){
			if(st[s2].find(*it)== st[s2].end()){
				++all;
			}else
				++ cnt;
		}

		printf("%0.1f%\n",100.0 * (float)cnt / (float)all);
		
	}
	
	return 0;
}
