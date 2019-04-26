#include "stdafx.h"
// string hash

// warning hash calculate 进制考虑低一位 26 * 26 * 10
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn =  26 * 26 * 26 * 10;
vector<int> sel[maxn];
int getId(char name[]){
	int ans = 0;
	for(int i=0; i<3;++i){
		ans = ans * 26 + name[i] - 'A';
	}
	return name[3]-'0' + ans * 10;
}
int main(){
	freopen("1039.txt", "r", stdin);
	int sn, cn;
	scanf("%d%d", &sn, &cn);
	int cid, seln;
	char name[5];
	for(int i=0; i<cn;++i){
		scanf("%d %d", &cid, &seln);
		for(int j=0; j<seln; ++j){
			scanf("%s",name);		
			sel[getId(name)].push_back(cid);
		}
	}
	for(int i =0; i<sn; ++i){
		scanf("%s", &name);
		int s = sel[getId(name)].size();

		printf("%s %d", name, s);
		
		sort(sel[getId(name)].begin(), sel[getId(name)].end());
		for(int j =0; j<s; ++j){
			printf(" %d", sel[getId(name)][j]);
		}
		printf("\n");
	}
	return 0;
}