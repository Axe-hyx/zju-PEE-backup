#include "stdafx.h"

#include <cstdio>
// char array 比较需用 strcmp < 0
// 根据string 统计总时长 考虑map
// in out 匹配原则可认为最近in out 组合才匹配 根据id进行排序 遍历即可
// 注意查询按顺序 因此按照时间排序 统计即可

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include <map>
using namespace std;
map <string , int> tb;
#define maxn 10010
struct record{
	char id[8];
	char status[4];
	int time;
}rec[maxn], val[maxn];
bool cmp(record a, record b){
	if(strcmp(a.id,b.id)) return strcmp(a.id, b.id) < 0;
		return a.time < b.time;
}

bool cmpt (record a, record b){
	return a.time < b.time;
}

int tonum(int hh, int mm, int ss){
	return hh * 3600 + mm * 60 + ss;
}
int main(){
	freopen("1095.txt", "r", stdin);
	int n,m;
	int hh, mm, ss;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i){
		scanf("%s %d:%d:%d %s", rec[i].id,&hh, &mm, &ss,rec[i].status);	

		rec[i].time = tonum(hh, mm, ss);

	}

	int num =0, maxtime =0;
	sort(rec, rec+n, cmp);
	for(int i =0; i<n-1; ++i){
		if(!strcmp(rec[i].id, rec[i+1].id)
			&& !strcmp(rec[i].status, "in")
			&& !strcmp(rec[i+1].status, "out")){
			
			val[num++] = rec[i];
			val[num++] = rec[i+1];
			int duration =  rec[i+1].time - rec[i].time;
			string s = string(rec[i].id, 8);
			if(tb.count(s) ==0)
				tb[s] = 0;
			tb[s] += duration;
			if(tb[s] > maxtime)
				maxtime = tb[s];
			
		}	
	}
	sort(val, val+num, cmpt);
	
	int p = 0, pnum =0;
	for(int i =0; i<m; ++i){
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = tonum (hh, mm, ss);
		while(p < num && time >= val[p].time){
			if(!strcmp(val[p].status, "in"))
				++pnum;
			else
				--pnum;
			++p;
		}
		printf("%d\n", pnum);
		if(p == num)break;
	}

	
	for(map<string ,int >::iterator it  = tb.begin();it!=tb.end(); ++it){
		if(it->second ==maxtime){
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 /60, maxtime % 60);
	

	return 0;

}