#include "stdafx.h"

// cmp 中引入 now 变量 方便排序
// 四舍五入


#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 0x3fffffff

struct student{
	int grade[4];
	int id;
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};
int Rank [1000000][4] = {0};
int now;
bool cmp(student a, student b){
	return a.grade[now] > b.grade[now];
}
using namespace std;
int main(){
	freopen("1012.txt", "r", stdin);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		scanf("%d", &stu[i].id);
		for(int j = 1; j<=3;++j){
			scanf("%d", &stu[i].grade[j]);
		}
		stu[i].grade[0] = (stu[i].grade[1]+ stu[i].grade[2]+stu[i].grade[3]) /3.0 + 0.5;  
	}
	for(now=0; now<4;++now){
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][now] = 1;
		for(int j =1 ; j< n;++j){
			if(stu[j].grade[now] == stu[j-1].grade[now]) Rank[stu[j].id][now] = Rank[stu[j-1].id][now];
			else  Rank[stu[j].id][now]  = j+1;
		}
	}
	for(int i= 0; i<m;++i){
		int id;
		cin >>id;
		if(Rank[id][0] == 0) {
			printf("N/A\n");
		}else{
			int r =INF, c=  0;
			
			for(int j=0;j<4;++j){
				if(r > Rank[id][j]){ 
					r = Rank[id][j];
					c = j;
				}
			}
			printf("%d %c\n", r, course[c]);
		}
	}
	return 0;
}