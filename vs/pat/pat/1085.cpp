#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

// 双指针 i j 同向增长
void sol_bin(){
	freopen("1085.txt", "r", stdin);

	int n,p;
	cin>>n>>p;
	int t[100010];
	for(int i=0; i<n; ++i){
		cin>>t[i];
	}
	
	sort(t, t+n);
	int max = 1;
	for(int i=0; i<n;++i){
		int l = i + 1, r = n-1;
		long long an = p * t[i];
		if( t[r]<= an && max < n-i) {
			max = n - i;
			continue;
		}
		while(l < r){ 
			int mid = (l + r)/2;
			if(t[mid] > an) r = mid;
			else l = mid +1;
		}
		if(l - i > max) max = l - i;
	}
	cout<<max<<endl;
}
// 找到第一个大于 的pos 注意处理界外情况
int main(){
	freopen("1085.txt", "r", stdin);
	int n, p;
	cin>>n>>p;
	int num [100010];
	for(int i =0; i<n; ++i){
		cin>>num[i];
	}
	sort(num, num +n);
	int i =0, j =0;
	int ans = 1;
	while(i<n && j <n){
		while(j<n && num[j] <= (long long ) num[i] * p){
			++j;
			ans = max(ans, j-i);
		}
		++i;
	}
	cout<<ans<<endl;
	
}