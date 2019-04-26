#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int main(){
	freopen("1117.txt", "r", stdin);
	int n;
	cin>>n;
	
	vector<int> v;
	v.resize(n);
	for(int i =0; i<n; ++i){
		cin>>v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int e =0;
	while(e<n && v[e] > e+1) ++e;
	cout<<e;
	return 0;
}
