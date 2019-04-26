#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;



struct person{
	int worth, age;
	
	char name[9];
}per[100010], vaild[100010];

bool cmp2(person a, person b){
	return a.age < b.age;
}
bool cmp(person a, person b){
	if(a.worth!=b.worth) return a.worth > b.worth;
	else if(a.age !=b.age) return a.age < b.age;
	else return strcmp(a.name,b.name) <0;
}
int main(){
	freopen("1055.txt", "r", stdin);
	int n,k;
	cin>>n>>k;
	for(int i =0; i<n; ++i){
		cin>>per[i].name>>per[i].age>>per[i].worth;
	
	}
	sort(per, per+n, cmp2);
	int cnt =1;

	int num = 0;
	for(int i =0; i<n; ++i){
		if(i ==0 || per[i].age == per[i-1].age && cnt <= 100 || per[i].age != per[i-1].age){
			vaild[num++] = per[i];
		}
			
	}
	sort(vaild, vaild+num, cmp);
	for(int i =0; i<k;++i){
		int m, min ,max;
		cin>>m>>min>>max;
		printf("Case #%d:\n", i+1);
		int p =m;
		for(int j=0; j<num && m!=0;++j){
			if(vaild[j].age <= max && vaild[j].age >=min) {
				printf("%s %d %d\n", vaild[j].name, vaild[j].age, vaild[j].worth);
				--m;
			}
		}
		if(p == m)
			printf("None\n");
		
	}

	return 0;
}