#include <iostream>
using namespace std;
double ans = 0.0;
int main(){
	int n;
	cin>>n;
	
	double temp;
	for(int i=1; i<=n; ++i){
		cin>>temp;
		ans += temp * i * (n-i+1);
	}
	printf("%.2lf",ans);
	return 0;
} 
