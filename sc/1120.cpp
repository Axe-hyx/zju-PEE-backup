#include <bits/stdc++.h>
using namespace std;
int getd(int num){
	int sum = 0;
	while(num!=0){
		sum +=num % 10;
		num /=10;
	}
	return sum;
}

int main(){
	freopen("1120.txt", "r", stdin);
	set<int> s;
	int n,t;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>t;
		s.insert(getd(t));
	}
	
	printf("%d\n", s.size());
	for(auto i = s.begin(); i!=s.end(); ++i){
			if(i!= s.begin()){
				printf(" ");
			}	
			printf("%d", *i);
	}
	
	return 0;
}
