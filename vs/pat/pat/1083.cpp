#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 60
struct student{
	int gra;
	char name[11];
	char id[11];
}stu[maxn];

bool cmp(student &a, student &b){
	return a.gra > b.gra;
}
int main(){
	freopen("1083.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n;++i){
		scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].gra);
	
	}
	sort(stu, stu+n, cmp);
	int a, b;
	scanf("%d %d", &a, &b);
	bool flag = false;
	for(int i =0; i<n;++i){
		printf("%s %s %d\n", stu[i].name, stu[i].id, stu[i].gra);
		if(stu[i].gra>=a && stu[i].gra<=b){
			flag = true;
			//printf("%s %s\n", stu[i].name,  stu[i].id);
		}
	}
	if(!flag){
		printf("NONE\n");
	}
	return 0;
}