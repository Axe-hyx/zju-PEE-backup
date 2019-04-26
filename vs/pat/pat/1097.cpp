#include "stdafx.h"

#include <iostream>
#include <vector>
using namespace std;
vector<int> va;
vector<int> vb;

struct Node{
	int addr, data, next;
	bool s;
}node[100010];
bool ex[10010] = {0};


int main(){
	freopen("1097.txt", "r", stdin);
	int st, n;
	cin>>st>>n;
	for(int i =0; i<n;++i){
		int addr;
		cin>>addr;
		cin>>node[addr].data>>node[addr].next;
		node[addr].addr = addr;
	}
	
	int p = st, cnt= 0, del = 0, dt=-1;
	while(p != -1){
		int a = node[p].data;
		a = a < 0 ? -a : a;
		if(ex[a] == true){
			++del;
			if(dt == -1){
				dt = p;
			}
			vb.push_back(p);
			node[p].s = false;
		}else {
			node[p].s = true;
			va.push_back(p);
			ex[a] = true;
		}
		p = node[p].next;
		++cnt;
	}

	int len;
	
	len = va.size();
	for(int i =0;i<len;++i){
		if(i!= len-1)
			printf("%05d %d %05d\n", node[va[i]].addr, node[va[i]].data, node[va[i+1]].addr);
		else 
			printf("%05d %d -1\n", node[va[i]].addr, node[va[i]].data);
	}
	
	len = vb.size();
	for(int i =0;i<len;++i){
		if(i!= len-1)
			printf("%05d %d %05d\n", node[vb[i]].addr, node[vb[i]].data, node[vb[i+1]].addr);
		else 
			printf("%05d %d -1\n", node[vb[i]].addr, node[vb[i]].data);
	}

}