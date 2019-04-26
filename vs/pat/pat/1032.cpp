#include "stdafx.h"

#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
struct Node{
	int nxt;
	int data;
}n1[maxn], n2[maxn];
int nxt[maxn];
char data[maxn];
int num1= 0, num2 = 0;
int main(){
	freopen("1032.txt", "r", stdin);
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	int a,c;
	char b;
	for(int i =0; i<n;++i){
		scanf("%d %c %d", &a, &b, &c);
		data[a] = b;
		nxt[a] = c;
	}
	int p1 =  s1;
	while(p1!=-1){
		++num1;
		p1 = nxt[p1];
	}
	
	int p2 = s2;
	while(p2!=-1){
		++num2;
		p2 = nxt[p2];
	}
	
	if(num1 < num2){
		swap(num1, num2);
		swap(s1, s2);
	}
	int t = num1 - num2;
	p1 = s1;
	p2 = s2;
	while(t--){
		p1 = nxt[p1];
	}
	while(p1!=-1 && p1 != p2){
		p1 = nxt[p1];
		p2 = nxt[p2];
	}		
	if(p1 != -1)	
		printf("%05d", p1);
	else printf("-1");


	
	return 0;
}