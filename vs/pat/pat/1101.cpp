#include "stdafx.h"
#include <iostream>
using namespace std;

#define INF 1e9 + 10
const int maxn = 100010;
int t[maxn];
int leftm[maxn], rightm[maxn];
int main(){
	freopen("1101.txt", "r", stdin);
	int n;	
	cin>>n;
	
	for(int i=0; i<n; ++i){
		cin>>t[i];

		
	}
	leftm[0] = 0;	
	for(int i=1; i<n; ++i){
		leftm[i] = leftm[i-1];
		if(t[i-1] > leftm[i])
			leftm[i] = t[i-1];
		
	}

	rightm[n-1] = INF;
	for(int i = n-2; i>=0; --i){
		rightm[i] = rightm[i+1];
		if(t[i+1] < rightm[i])
			rightm[i] = t[i+1];
		
	}
	int ans[maxn];
	int pnum = 0;
	
	
	for(int i = 0; i<n; ++i){
		
		if(t[i] > leftm[i] && t[i] < rightm[i]){
			ans[pnum++] = t[i];
		}
	}
	
	cout<< pnum<<endl;
	for(int i = 0; i<pnum; ++i){
		if(i!=0)
			cout<< " ";
		cout<<ans[i];
	}
	cout<<endl;

	

	return 0;
}