#include "stdafx.h"

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;

struct school{
	char nam[7];
	int rank, cnt;
	double total;
}stu[maxn];

bool cmp(school a, school b){
	return strcmp(a.nam, b.nam)<0;
}

bool cmp2(school &a, school &b){
	if((int)a.total != (int)b.total)return (int)a.total > (int)b.total;
	else if(a.cnt != b.cnt) return a.cnt < b.cnt;
	return strcmp(a.nam,b.nam)<0;
	
}

int main(){
	freopen("1141.txt", "r", stdin);
	int n;
	cin>>n;
	char t, cha[7];
	int id, sco;
	vector<school> vec(n);
	int sz;
	for(int i =0; i<n; ++i){
		cin>>t>>id>>sco>>cha;
		sz = strlen(cha);
	
		for(int j=0; j<sz;++j){
			if(cha[j] >='A' && cha[j] <= 'Z') cha[j] += 32;
			strcpy(stu[i].nam, cha);
			if(t == 'B') stu[i].total = sco /1.5 ;
			else if(t == 'T') stu[i].total = sco * 1.5;
			else stu[i].total = sco;
		}
	}

	sort(stu, stu+n, cmp);
	
	int snum =0;
	int cnt =0;
	for(int i =0; i<n;++i){
		if(i==0 || strcmp(stu[i].nam, vec[snum-1].nam)){
			struct school t;
			t.cnt = 1;
			strcpy(t.nam, stu[i].nam);
			t.total = stu[i].total;
			vec[snum] =t;
			++snum;
		}else{
			++vec[snum-1].cnt;
			vec[snum-1].total +=stu[i].total;
		}
	}
	sort(vec.begin(), vec.begin()+snum, cmp2);
	cout<<snum<<endl;
	int rank =1;
	for(int i=0; i<snum;++i){
		if(i!=0 && (int)vec[i].total != (int)vec[i-1].total) rank = i +1 ;
		printf("%d %s %d %d\n", rank, vec[i].nam, (int)vec[i].total,vec[i].cnt);
	}
}