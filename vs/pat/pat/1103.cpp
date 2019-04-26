#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


// positive integers except index == 0
int fac[21];
vector<int> ans, temp;
int fsum = -1;
int n, k, p;

void dfs(int index, int facsum, int sum, int nk){
	if(nk >k || sum > n) return;
	if(nk == k && sum ==n) {
		if( facsum > fsum){
			ans = temp;
			fsum = facsum;
		}
		return;
	}
	
	if(index >=1){ //positive integers
		temp.push_back(index);
		dfs(index, facsum+index, sum+fac[index], nk+1);
		temp.pop_back();
		dfs(index -1, facsum, sum, nk);
	}
}
int main(){
	freopen("1103.txt", "r", stdin);
	cin>>n>>k>>p;

	fac[0] = 1;// i * p
	int fs =1, index;
	for(index =1; fs<n; ++index){
		fs= (int)pow(index * 1.0, p);
		fac[index] = fs;
	}
	--index;
	dfs(index,0,0,0);
	
	if(ans.size()!=0){
		printf("%d =", n);
		for(int i=0; i<ans.size(); ++i){
			if(i!=0){
				printf(" + %d^%d", ans[i], p);
			}else 
			printf(" %d^%d", ans[i], p);
		
		}	
	}else
		printf("Impossible\n");
	
	return 0;
}