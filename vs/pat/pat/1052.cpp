#include "stdafx.h"

#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010
struct Node{
	int addr;
	int next;
	int key;
	int flag;
}node[maxn];

bool cmp(Node a, Node b){
	if(a.flag ==0 || b.flag ==0)
		return a.flag > b.flag;
	return a.key < b.key;	
}
int main(){
	//freopen("1052.txt", "r", stdin);
	int n, s1;
	
	scanf("%d %d", &n, &s1);
	int addr;
	
	for(int i =0;i<maxn; ++i){
		node[i].flag = 0;
	}
	for(int i =0;i<n; ++i){
		scanf("%d", &addr);
		node[addr].addr = addr;
		scanf("%d %d", &node[addr].key, &node[addr].next);
		
	}
	int p1 = s1;
	
	int cnt = 0;
	while(p1!=-1){
		++cnt;
		node[p1].flag = 1;
		p1 = node[p1].next;		
		
	}
	sort(node, node+maxn,cmp);
	if(cnt == 0){
		printf("0 -1\n");
		return 0;
	}	

	printf("%d %05d\n", cnt, node[0].addr);
	for(int i =0;i<cnt;++i){
		if(i>0)
			printf(" %05d\n", node[i].addr);
		printf("%05d %d", node[i].addr, node[i].key);
	}
	printf(" -1\n");


	return 0;
}