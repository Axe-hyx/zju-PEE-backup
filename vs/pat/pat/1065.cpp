#include "stdafx.h"
//注意负溢出条件，-2^64 long long 表示为0
#include <cstdio>
typedef long long LL;

int main(){
	freopen("1065.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	LL a,b,c;
	int t = 1;
	bool flag;
	
	for(int i=0; i<n;++i){
		scanf("%lld%lld%lld", &a, &b, &c);
		LL ans = a + b;
		if(a > 0 && b > 0 && ans <0) flag = true;
		else if(a < 0 && b < 0 && ans >=0) flag = false;
		else if (ans > c) flag = true;
		else flag = false;
		printf("Case #%d: ",t++);
		if(flag) printf("true\n");
		else printf("false\n");
	}
	return 0;
}