#include "stdafx.h"

#include<iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<int > st;
const int maxn = 1e5 + 10;
const int sqr = 316;
int block[sqr], hashtable[maxn];
void pop(){
	int t = st.top();
	cout<<t<<endl;
	st.pop();
	--block[t/sqr];
	--hashtable[t];
}
void push(int x){
	st.push(x);
	++block[x/ sqr];
	++hashtable[x];
}
void peekmedian(int i){
	int sum =0, idx = 0;
	while(sum + block[idx] < i){
		sum += block[idx++];
	}
	int num = idx * sqr;
	while(sum + hashtable[num] < i){
		sum+=hashtable[num++];
	}
	cout<<num<<endl;
}
int main(){
	freopen("1057.txt", "r", stdin);
	int n,t;
	cin>>n;
	char cmd[20];
	for(int i=0; i<n; ++i){
		scanf("%s", cmd);
		if(strcmp(cmd, "Push") == 0){
			int t;
			cin>>t;
			push(t);
		}else if(strcmp(cmd, "Pop") == 0){
			if(st.empty()){
				cout<<"Invalid"<<endl;
			}else 
				pop();
		}else
		{
			if(st.empty()){
				cout<<"Invalid"<<endl;
			}else {
				int sz = st.size();
				if(sz % 2== 1) peekmedian( (sz + 1)/2);
				else peekmedian(sz/2);
			}
		}
	}
	return 0;
}6