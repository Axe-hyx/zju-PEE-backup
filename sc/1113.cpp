#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("1113.txt", "r", stdin);
	int n, num;
	cin>>n;
	vector<int>v;
	v.resize(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int sum =0,b;
	for(int i =0; i<n; ++i)
	{
		if(i == n/2) b = sum;
		sum += v[i];
		
	}
	printf("%d %d", n%2,sum- b * 2);
	return 0;
}
