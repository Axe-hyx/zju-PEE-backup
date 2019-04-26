#include "stdafx.h"

#include <cstring>
#include <stdio.h>

int am[128] = {0};

int main(){
	freopen("1092.txt", "r", stdin);
	char a[1010], b[1010];

	fgets(a, 1010, stdin);
	fgets(b, 1010, stdin);
	
	int as = strlen(a);
	int bs = strlen(b);
	int sum =0;
	for(int i=0; i<as-1; ++i){
		++am[a[i]];
		++sum;
	}
	
	int neg = 0;
	for(int i =0; i<bs-1; ++i){
		if(am[b[i]]){
			--sum;
			--am[b[i]];
		}else{
			++neg;
		}
		
	}
	if(neg>0) printf("No %d", neg);
	else printf("Yes %d", sum);
	return 0;
}