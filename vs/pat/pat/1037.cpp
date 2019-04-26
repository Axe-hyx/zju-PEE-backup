#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;
int a[100010], b[100010];
int main(){
	freopen("1037.txt", "r", stdin);
	int n,m;
	cin>>n;
	
	for(int i =0; i<n;++i){
		cin>>a[i];
	}
	cin>>m;
	
	for(int i =0; i<m;++i){
		cin>>b[i];
	}

	sort(a, a+ n);
	sort(b, b+ m);
	int l=0, r=0;
	int ans = 0;
	while(l<n && r <m &&a[l] < 0 && b[r]<0){
		ans += a[l] * b[r];
		++l;
		++r;
	}
	l = n -1 , r = m-1;
	while(l>=0&& r>=0 &&a[l] > 0 && b[r]>0){
		ans += a[l] * b[r];
		--l;
		--r;
	}
	cout<<ans;
	return 0;
}
