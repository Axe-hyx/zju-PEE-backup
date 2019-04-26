#include "stdafx.h"


// cmp ÓÐ½²¾¿
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string a, string b){
	return a + b < b + a;
}

string tb[10010];
int main(){
	freopen("1038.txt", "r", stdin);
	int n;
	cin>>n;
	string k;
	for(int i=0; i<n; ++i){
		cin>>k;
		tb[i] = k;
	}
	sort(tb, tb + n, cmp);
	string ans ="";
	for(int i =0; i<n; ++i){
		ans += tb[i];
	}
	while(ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0)
		cout<<0<<endl;
	else cout<<ans;
}