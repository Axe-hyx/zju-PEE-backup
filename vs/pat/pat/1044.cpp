#include "stdafx.h"


// upper_bound 复习 初始区间及查找成功失败条件！
#include <iostream>
using namespace std;
#define INF 0x3fffffff
int sum[100010] = {0};
int main(){
	freopen("1044.txt","r", stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>sum[i];
		sum[i] += sum[i-1];
	}
	

	int up = INF;

	for(int i=1; i<=n; ++i){
		int l = i, r= n+1;
		while(l<r){
			int mid = (l+r)/2;
			if(sum[mid] - sum[i-1] > m) r = mid;
			else l = mid + 1;
		}
		if(sum[l-1] - sum[i-1] ==m ){
			up = m;
			break;
		}
		else if(l <= n && sum[l] - sum[i-1] < up){
				up = sum[l] - sum[i-1];
		}
	}
	
	for(int i=1; i<=n; ++i){
		int l = i, r = n+1;
		while(l < r){
			int mid  = (l + r) /2;
			if(sum[mid] -  sum[i-1] > up) r = mid;
			else l = mid + 1;
		}
		if(sum[l-1] - sum[i-1] == up) cout<<i<<"-"<<l-1<<endl;
		
	}
}