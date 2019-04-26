#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;

int coi[100010];
void sol_bin(){
	freopen("1048.txt", "r", stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		cin>>coi[i];
	}
	sort(coi, coi + n);
	for(int i =0; i<n;++i){
		int left = i+1, right = n-1;
		int x = m-coi[i];
		int mi = -1;
		while(left <= right){
			int mid = (left + right) /2;
			if(coi[mid] == x) {
				mi = mid; 
				break;
			}
			else if(coi[mid] > x) 
				right = mid -1;
			else left = mid + 1;
		}
		if(mi != -1){
			printf("%d %d", coi[i], coi[mi]);
		}
	}
	printf("No Solution\n");
}
int main(){
	freopen("1048.txt", "r", stdin);
	int n, m;
	cin>>n>>m;
	for(int i =0; i<n; ++i){
		cin>>coi[i];
	}
	sort(coi, coi+ n);
	int l = 0, r = n-1;
	while(l<r){
		if(coi[l] + coi[r] == m){
			break;
		}else if(coi[l] + coi[r] > m)
			--r;
		else ++l;
	}
	if(l<r)
		printf("%d %d", coi[l], coi[r]);
	else 
		printf("No Solution\n");

	return 0;
}