#include "stdafx.h"

#include <iostream>

int main(){
	int p[32]={0},pnum=0;
	int n, b;
	scanf("%d %d", &n, &b);
	do{
		p[pnum++] = n % b;
		n/=b;
	}while(n!=0);

	bool flag = true;
	for(int i=0;i<=pnum/2;++i){
		if(p[i] != p[pnum - i -1]) flag = false;
	}

	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	if(pnum==0)
		printf("0");
	else
		for(int i=pnum-1; i>=0; --i){
			printf("%d", p[i]);
			if(i!=0)
				printf(" ");

		}



}