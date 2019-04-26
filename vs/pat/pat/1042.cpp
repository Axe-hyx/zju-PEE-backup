#include "stdafx.h"
// 1 - 54 对应花色 以及 牌号的推导
#include <cstdio>
char sn[5] = {'S', 'H', 'C', 'D', 'J'};
int start[55], end[55];
int no[55];
void to(){
	for(int i= 1; i<= 54; ++i){
		end[no[i]] = start[i];
	}
	for(int i= 1; i<= 54; ++i){
		start[i] = end[i];
	}
}
int main(){
	freopen("1042.txt","r",stdin);
	int n;
	scanf("%d", &n);
	
	for(int i =1; i<55; ++i){
		start[i] = i; 
	}
	for(int i =1; i<55; ++i){
		scanf("%d", &no[i]);
	}

	while(n--){
		to();
	}
	for(int i=1; i<55; ++i){
		if(i>0)
			printf(" ");
		printf("%c%d", sn[(start[i]-1)/13], (start[i]-1)%13+1);
	}
	
	return 0;
}
