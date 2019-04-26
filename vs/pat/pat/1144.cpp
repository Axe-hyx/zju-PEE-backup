#include "stdafx.h"

#include <iostream>
#include <map>
using namespace std;
map <int, int> tb;
const int mint = -((1<<31)+1);
int main(){
	freopen("1144.txt", "r", stdin);
	int n;
	cin>>n;
	int t;
	int num=0;
	while(n--){
		cin>>t;
		tb[t] = 1;
	}
	while(++num){
		if(tb.count(num) == 0)
			break;
	}
	if(num == mint)
		printf("1\n");
	else 
		printf("%d\n", num);
	return 0;
}