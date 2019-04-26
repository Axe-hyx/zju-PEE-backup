#include "stdafx.h"
// ¸´Ï° upper_bound
//
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e5;
bool ex[maxn] = {0};

int main(){
	freopen("1145.txt", "r", stdin);
	
	int ms, n,m;
	cin>>ms>>n>>m;

	ex[0] = ex[1] = true;
	for(int i = 2; i< maxn; ++i){
		if(ex[i] == false){
			for(int j = i + i; j<maxn; j+=i){
				ex[j] =true;
			}
		}
	}
	while(ex[ms]){
		++ms;
	}
	
	int table[10010]= {0};
	for(int i =0; i<n; ++i){
		int a;
		cin >>a;
		bool flag = false; 
		for(int j =0; j<=ms; ++j){
			int pos = (a + j *j ) % ms;
			if(table[pos] == 0){
				table[pos]= a;
				flag = true;
				break;
			}
			
		}
		if(!flag ) printf("%d cannot be inserted\n", a);
	}

	int ans = 0;;
	for(int i = 0; i<m; ++i){
		int a;
		cin>>a;
		for(int j = 0; j<=ms; ++j){
			++ans;
			int pos = (a + j* j)% ms;
			if(table[pos] == 0 || table[pos] == a) break;
		}		
	}
	printf("%.1f\n", ans * 1.0 /m);
	return 0;
}