#include "stdafx.h"

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define maxs 2510
#define maxc 40010
vector<int> sel[maxc];
const int M = 26 * 26 * 26 * 10;
char sname[M][5];

int getId(char name[5]){
	int ans = 0;
	for(int i=0; i<3; ++i){
		ans  = ans * 26 + name[i]-'A';
	}
	return ans * 10 + name[3] - '0';
}
int main(){
	freopen("1047.txt", "r", stdin);
	int sn, cn;
	scanf("%d %d", &sn ,&cn);
	char name[5];
	int seln, cid;
	for(int i =0; i<sn; ++i){
		scanf("%s%d", &name, &seln);
		sprintf(sname[getId(name)], "%s", name);
		for(int j = 0; j< seln; ++j){
			scanf("%d", &cid);
			sel[cid].push_back(getId(name));
		}
	}
	for(int i =1;i<=cn;++i){
		sort(sel[i].begin(), sel[i].end());
		int s = sel[i].size();
		printf("%d %d\n", i, s);
		for(int j = 0; j<s;j++){
			printf("%s\n",  sname[sel[i][j]]);
		}
	}
	return 0;
}

