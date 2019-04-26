#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> rnk;
unordered_map<string, bool> check;
bool isprime(int i){
	if(i==1 || i ==0) return false;
	for(int k =2; k*k <=i; ++k){
		if(i%k ==0) return false;
	}
	return true;
}
int main(){
	freopen("1116.txt", "r", stdin);
	int n;
	cin>>n;
	string name;
	for(int i=1; i<=n; ++i){
		cin>>name;
		rnk[name] = i;
	}
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>name;
		printf("%s: ", name.c_str());
		
		if(rnk.count(name) ==0){
			printf("Are you kidding?");
		}else{
			if(check.count(name) == 0)
			check[name] = true;
			else{
				printf("Checked\n");
				continue;
			}
			int r = rnk[name];
			if(r == 1){
				printf("Mystery Award");
			}else if(isprime(r)){
				printf("Minion");
			}else printf("Chocolate");
		}
		printf("\n");
	}
	return 0;
}
