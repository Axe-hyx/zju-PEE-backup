#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct student{
	int de,ca,total;
	int id;
	int flag;
}stu[100010];

bool cmp(student a, student b){
	if(a.flag != b.flag) return a.flag < b.flag;
	else if(a.total != b.total) return a.total > b.total;
	else if(a.de !=b.de) return a.de > b.de;
	else return a.id < b.id;
}
int main(){
	freopen("1062.txt", "r", stdin);
	int n, l,h;	
	cin>>n>>l>>h;
	
	int all = n;
	for(int i=0; i<n; ++i){
		int id, de, ca;
		cin>>id>>de>>ca;

		stu[i].id = id;
		stu[i].de = de;
		stu[i].ca = ca;
		stu[i].total = de + ca;
		if(de <l || ca <l) {
			stu[i].flag = 5;
			--all;
			continue;
		}
		if(de >= h && ca >= h) stu[i].flag= 1;
		else if(de >= h && ca <h) stu[i].flag =2;
		else if (de >= ca ) stu[i].flag =3;
		else stu[i].flag  = 4;	
	}

	sort(stu, stu+n, cmp);
	
	printf("%d\n",all);
	for(int i=0; i<all; ++i){
		printf("%d %d %d\n", stu[i].id, stu[i].de, stu[i].ca);
	}
	return 0;
}