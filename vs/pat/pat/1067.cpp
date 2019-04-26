#include "stdafx.h"


// 最后一次swap 将会调整最后两个元素位置 left 仅需设为 n-1
// 注意while 执行 left 次， for循环每次重头枚举 10^ 10 平方级复杂度，tle
// 利用排序性质，每次找到k仅用常数倍时间

#include <iostream>
using namespace std;
int t[100010];
int main(){
	freopen("1067.txt", "r", stdin);
	int n, left, tmp;
	cin>>n;
	left = n-1;
	
	for(int i=0; i<n; ++i){
		cin>>tmp;
		t[tmp] = i;
		if(tmp != 0 && i==tmp) --left;
	}

	int ans = 0;

	int k = 1;
	while(left >0){
		if(t[0] == 0){
			for(;k<n;){
				if(t[k] != k){
					++ans;
					swap(t[k],t[0]);
					break;
				}
				++k;
			}
		}
		while(t[0] != 0){
			swap(t[0],t[t[0]]);
			--left;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}