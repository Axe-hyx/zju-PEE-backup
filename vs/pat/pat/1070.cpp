#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;
struct mooncake{
	double price;
	double amount;
	double sell;
}moon[1010];
bool cmp(mooncake a, mooncake b){
	return a.price > b.price;
}
int main(){
	freopen("1070.txt", "r", stdin);
	int n;
	double d;
	cin>>n;
	cin>>d;
	for(int i =0; i<n; ++i){
		cin>>moon[i].amount;
	}
	for(int i =0; i<n; ++i){
		cin>>moon[i].sell;	
		moon[i].price = moon[i].sell / moon[i].amount;
	}
	sort(moon, moon +n, cmp);
	
	
	double ans =0.0;
	for(int i =0; i<n; ++i){
		if(moon[i].amount <= d)	{
			d -=moon[i].amount;
			ans += moon[i].sell;
		}else{
			ans += moon[i].price * d;
			break;
		}
	}
	printf("%0.2lf", ans);
	return 0;
}