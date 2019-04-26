#include "stdafx.h"

// 精髓在于预处理
#include <stdio.h>
#include <cstring>
bool key[256] = {false}, pri[256]= {false};
int main(){
	freopen("1084.txt", "r", stdin);
	char a[82], b[82];
	fgets(a, 82, stdin);
	fgets(b, 82, stdin);
	
	int az = strlen(a);
	int bz = strlen(b);
	
	for(int i=0; i<bz;++i){
		if(b[i]>='a'&& b[i]<='z') b[i] -=32;
		key[b[i]] = true;
	}
	for(int i=0; i<az; ++i){
		if(a[i]>='a' && a[i]<='z') a[i] -=32;
		if(!key[a[i]] && !pri[a[i]]){ 
			printf("%c", a[i]);
			pri[a[i]] = true;
		}
	}
	return 0;
}