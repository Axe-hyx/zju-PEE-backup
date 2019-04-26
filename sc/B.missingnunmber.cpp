#include <iostream>

using namespace std;
const int maxn = 1e7 + 10;
long long a[maxn];
int n;

int main(){
	//freopen("4.in", "r", stdin);

	scanf("%d", &n);
	for(int i =1; i<=n; ++i){
		scanf("%lld", &a[i]);
	}
	int ans = 0;
	for(int i =1; i<=n; ++i){
		while(a[i] > 0 && a[i] <=n && a[i] != a[a[i]]){
			swap(a[i], a[a[i]]);
		}
	} 
	for(int i =1; i<=n; ++i){
		if(a[i] != i){
			ans = i;
			break;
		}
	}
	
	printf("%d\n", ans == 0 ? n +1 : ans	);
	return 0;
}
