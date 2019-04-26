#include "stdafx.h"

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>
struct record{
	char name[21];
	bool status;
	int mouth, dd, hh, mm;
}rec[1010];

bool cmp(record &a, record&b){
	
	if(strcmp(a.name, b.name)!=0) return strcmp(a.name, b.name) <0;
	else if(a.mouth != b.mouth )return a.mouth < b.mouth;
	else if(a.dd != b.dd) return a.dd < b.dd;
	else if(a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}
int rate[24]; 
void getamout(int i, int &money, int &mm){
	while(rec[i-1].dd < rec[i].dd||rec[i-1].hh < rec[i].hh||rec[i-1].mm < rec[i].mm){
		++rec[i-1].mm;
		++mm;
		money +=rate[rec[i-1].hh];
		if(rec[i-1].mm == 60){
			rec[i-1].mm = 0;
			++rec[i-1].hh;
		}
		if(rec[i-1].hh == 24){
			rec[i-1].hh=0;
			++rec[i-1].dd;
		}
	}
}

int main(){
	freopen("1016.txt", "r", stdin);
	for(int i =0; i<24; ++i){
		cin>>rate[i];
	}
	int n;
	cin>>n;
	char s[10];
	for(int i=0; i<n; ++i){	
		scanf("%s %d:%d:%d:%d", rec[i].name, &rec[i].mouth, &rec[i].dd, &rec[i].hh, &rec[i].mm);
		scanf("%s", s); 
		if(strcmp(s, "on-line") == 0) rec[i].status = true;
		else rec[i].status = false;
	}
	sort(rec, rec+n, cmp);

	int st, nex;
	
	for(st=0;st<n;){	
		nex = st;
		bool flag = false;
		while(nex < n && strcmp(rec[nex].name, rec[st].name)==0){
			if(st !=nex && rec[nex-1].status == true && rec[nex].status == false){
				flag = true;
			}
			++nex;	
		}
		if(!flag){ 
			st = nex;
			continue;
		}
		printf("%s %02d\n", rec[st].name, rec[st].mouth);
		int ans = 0;
		for(int j=st+1; j< nex;++j){
			if(rec[j-1].status == true && rec[j].status == false
				&& strcmp(rec[j-1].name, rec[j].name) == 0
				&& rec[j-1].mouth == rec[j].mouth){
				printf("%02d:%02d:%02d ", rec[j-1].dd, rec[j-1].hh, rec[j-1].mm);
				printf("%02d:%02d:%02d ", rec[j].dd, rec[j].hh, rec[j].mm);
				int money =0, mm = 0;
				
				getamout(j, money, mm);
				ans +=money;
				printf("%d $%.2f\n", mm, money * 1.0 /100);
				
			}
		}
		printf("Total amount: $%.2f\n", ans * 1.0 /100);
		
		st = nex;

	}
	
	return 0;
}