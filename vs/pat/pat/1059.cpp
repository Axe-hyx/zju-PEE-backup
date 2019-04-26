//温习素数筛法
//对于素数表 只用生成 100010以内即可 sqrt(MAX_INT)
#include "stdafx.h"


#include <cstdio>
#define maxn 100010

struct factor{
	int cnt;
	int x;
}fac[10];

int prime[maxn];
bool p[maxn] = {0};
int pNum =0;
int fNum =0;


void Find_prime(int n){
	for(int i= 2; i<n; ++i){
		if(p[i] == false){
			prime[++pNum] = i;
			for(int j = i + i; j < n; j+=i){
				p[j] = true;
			}		
		}
	}

}
/*
bool isprime(int n){
	if(n ==1 ) return false;
	LL i; 
	for(i = 2; i * i<=n; ++i)
		if( n % i == 0)
			return false;
	
	return true;
}
void Find_prime(int n){
	for(int i = 1; i<n;++i){
		if(isprime(i)){
			debug(i);
			prime[pNum++] = i;
		}
	}
}
*/

int main(){
	int t;
	freopen("1059.txt", "r", stdin);
	scanf("%d", &t);	
	if(t == 1){
		printf("1=1");
		return 1;
	}

	Find_prime(maxn);
	int b = t;
	for(int i = 1; i< pNum; ++i){
		if(b % prime[i] == 0 ){
			
			fac[fNum].x = prime[i];
			fac[fNum].cnt = 0;
			while(b % prime[i] == 0){
				b /= prime[i];
				fac[fNum].cnt++;
			}
			++fNum;
		}
		if(b == 1) break;
	}
	if( b!=1 ){
		fac[fNum].cnt = 1;
		fac[fNum].x = b;
		++fNum;
	}


	printf("%d=",t);
	for(int i = 0; i< fNum; ++i){
		if(i>0)
			printf("*");
		printf("%d", fac[i].x);
		if(fac[i].cnt != 1)
			printf("^%d", fac[i].cnt);

	}

	return 0;
}
