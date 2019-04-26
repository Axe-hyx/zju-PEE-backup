#include "stdafx.h"


// 复习插入 归并排序
// 判同 中间步骤!!!!  step != 2 i !=1
#include <iostream>
#include <algorithm>
using namespace std;


const int m = 110;
int num[m], changed[m], ba[m];
int n;
bool issame(int a[], int b[]){
	for(int i=0; i<n; ++i){
		if(a[i] != b[i])
			return false;
	}
	return true;
}
bool Mergesort(){
	bool flag = false;
	for(int step =2; step/2<=n; step *=2){
		if(step!=2 && issame(num, changed)){
			flag = true;
		}
		for(int i=0; i<n; i+=step){
			sort(num + i, num +min(i + step, n));
		}
		if(flag) return true;
	}
	
	return false;
}
bool Insertsort(){ // 多运行一步
	bool flag = false;
	for(int i=1; i<n; ++i){
		if(i!=1 && issame(num, changed)){
			flag = true;
		}

		int t = num[i], j =i;
		while(j>0 && num[j-1] > t){
			num[j] = num[j-1];
			--j;
		}
		num[j] = t;

		if(flag)
			return true;
	}
	return false;
}
int main(){
	freopen("1089.txt", "r", stdin);
	cin>>n;
	for(int i =0; i<n; ++i){
		cin>>num[i];
		ba[i] = num[i];
	}
	for(int i =0; i<n; ++i){
		cin>>changed[i];
	}
	if(Mergesort())
		printf("Merge Sort\n");
	else{
		for(int i =0; i<n; ++i){
			num[i] = ba[i];
		}
		Insertsort();
		printf("Insertion Sort\n");
	}

	for(int i =0; i<n; ++i){
		if(i!=0)
			cout<<" ";
		cout<<num[i];
	}
	cout<<endl;
	

	return 0;
}