#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, num[maxn], ans[maxn], cnt=0;
void inor(int root){
	if(root> n) return;
	inor(root * 2);
	ans[root] = num[cnt++];
	inor(root * 2 + 1);
}
int main(){
	freopen("1064.txt", "r", stdin);
	cin>>n;
	for(int i =0; i<n; ++i){
		cin>>num[i];
	}
	sort(num, num +n);
	inor(1);
	for(int i =1; i<=n; ++i){
		if(i!=1)
			cout<<" ";
		cout<<ans[i];
	}
	return 0;

}