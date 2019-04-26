
/*
#include "stdafx.h"
#include <iostream>
using namespace std;
struct Node{
	int addr, data, next;
}node[100010];

int main(){
	freopen("1074.txt", "r", stdin);
	int st, n, k;	
	cin>>st>>n>>k;
	for(int i =0; i<n; ++i){
		int a;
		cin>>a;
		cin>>node[a].data>>node[a].next;
		node[a].addr = a;
	}
	int sp;
	int ans  = -1;
	sp = n / k;
	
	int ba  = st, cnt = 0;
	while(ba!=-1){
		++cnt;
		ba = node[ba].next;
	}
	int pre = st, p = st, q, bc;
	bool flag = false;
	int opc=-1, npc;

	for(int i =0; i< sp; ++i){
		int r;
		npc = p;
		for(int j = 0; j<k; ++j){
			if(j==0){
				q = p;
				p = node[p].next;
			}else{
				r = node[p].next;
				node[p].next = q;
				q = p;
				p =r;
			}
		}
		node[npc].next = p;
		if(opc !=-1){
			node[opc].next = q;
		}
		opc = npc;
		if(ans == -1)
			ans = q;
	}
	
	p = ans == -1? st:ans;
	n = cnt;
	cnt =0;
	while(p!=-1){
		++cnt;
		if(cnt != n){
			printf("%05d %d %05d\n", node[p].addr, node[p].data, node[p].next);
		}else{
			printf("%05d %d -1\n", node[p].addr, node[p].data);
		}
		
		p = node[p].next;
	}
	return 0;
}
*/

#include "stdafx.h"
#include  <iostream>
#include <algorithm>
using namespace std;
const int maxn  = 1e6 + 10;
struct Node{
	int addr, next, data;
	int order;
	Node(){
		order = maxn;
	}

}node[maxn];
bool cmp(Node a, Node b){
	return a.order < b.order;
}
int main(){
	freopen("1074.txt", "r", stdin);
	
	int st, n, k;
	cin>>st>>n>>k;
	for(int i=0; i<n; ++i){
		int a,b,c;
		cin>>a>>b>>c;
		node[a].addr = a;
		node[a].data = b;
		node[a].next = c;
	}
	int cnt = 0;
	int p = st;
	while(p!=-1){
		node[p].order= cnt;
		p = node[p].next;
		++cnt;
	}
	n = cnt;
	sort(node, node+maxn, cmp);
	
	for(int i =0; i<n/k; ++i){
		for(int j = k * (i+1) -1; j> k * i; --j){
			printf("%05d %d %05d\n", node[j].addr, node[j].data ,node[j-1].addr);
		}
		printf("%05d %d ", node[i*k].addr, node[i*k].data);
		if(i < n/k-1){
			printf("%05d\n", node[(i+2) * k -1].addr);
		}else{
			if(n % k == 0) printf("-1\n");
			else {
				printf("%05d\n", node[n/k * k].addr);
				for(int j = n / k * k; j< n; ++j){
					printf("%05d %d ", node[j].addr, node[j].data);
					if(j < n-1) printf("%05d\n", node[j+1].addr);
					else printf("-1\n");
				}
			}
		}

	}
	return 0;
}
