#include "stdafx.h"
// 打表
// 注意n2s 数字分割
// 注意非法输入， 对于打表题 数据范围过大会导致混入脏数据，且不易发现




#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#define maxn 169
using namespace std;

string unitd [13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string tend [12]= {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string n2s[170];
map<string, int> s2n;
void init(){
	for(int i =0; i<maxn;++i){
		if(i/13==0){ // 0 - 12
			n2s[i] = unitd[i];
		}else if(i % 13 == 0){ // 13 26
			n2s[i] = tend[i/13 -1];
		}else
			n2s[i] = tend[i/13-1]+ " " + unitd[i%13];
		s2n[n2s[i]] = i;
		//printf("%s\n", n2s[i].c_str());
	}
}
int main(){
	
	//freopen("1100.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	getchar();
	
	init();
	int i =0;

	while(n--){
		string c;
		getline(cin, c);		

		if(c[0]>='0' && c[0] <= '9'){
			int num = 0;
			for(int i = 0; i < c.length(); ++i){
				num = num * 10 + c[i] - '0';
			}
			printf("%s\n", n2s[num].c_str());
		}
		else{
			
			map<string, int>::iterator it = s2n.find(c);
			
				printf("%d\n", it->second);
			
		}
	}
	
	
	
	return 0;
}