#include "stdafx.h"

// cmp1 strcmp != 0 不可以写成 !strcmp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct record{
	int id;
	char name[9];
	int grade;
}stu[100010];


bool cmp (record a,record b){
	return a.id < b.id;
}

bool cmp1(record a, record b){
	int s = strcmp(a.name, b.name);
	if (s!= 0) return strcmp(a.name, b.name) <0;
	else return a.id < b.id;
}

bool cmp2(record a, record b){
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1028.txt", "r", stdin);
	int n,c;
	cin>>n>>c;
	for(int i=0; i<n;++i){
		cin>>stu[i].id>>stu[i].name>>stu[i].grade;
	}
	if(c == 1)
		sort(stu, stu +n, cmp);
	else if(c == 2)
		sort(stu, stu +n, cmp1);
	else 
		sort(stu, stu +n, cmp2);
	for(int i=0; i<n; ++i){
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}