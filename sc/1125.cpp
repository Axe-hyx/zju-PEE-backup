#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	
vector<int> v;
int main(){
	freopen("1125.txt","r", stdin);
	int n,num;
	cin>>n;
	v.resize(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int result = v[0];
	for(int i=1; i<n; ++i){
		result = (result + v[i])/2;
	}
	printf("%d", result);
	return 0;
	
}
