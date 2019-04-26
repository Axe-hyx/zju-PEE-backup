#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 110;
int n, changed[maxn], temp[maxn], heap[maxn];
bool issame(int a[], int b[]){
	for(int i=0; i<n; ++i){
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void adjustdown(int low, int high){
	int i = low, j = i * 2;
	while(j<=high){
		if(j+1 <=high && heap[j+1] > heap[j])
			++j;
		if(heap[j] > heap[i]){
			swap(heap[i], heap[j]);
			i  = j;
			j  = i * 2;
		}else 
			break;
	}
}
void createheap(){
	for(int i=n/2; i>=1; --i){
		adjustdown(i, n);
	}
}
bool heapsort(){
	createheap();
	bool flag = false;
	for(int i=n; i>=1; --i){
		if(i!=n && issame(heap, changed))
			flag = true;
		swap(heap[1], heap[i]);
		adjustdown(1, i-1);
		if(flag)
			return true;
	}
	return false;
} 


bool insertsort(int a[]){
	bool flag = false;

	for(int i =2; i<=n; ++i){
		if(i !=2 && issame(a, changed)) flag = true;
		int t = a[i], j = i-1;
		for(; j>=1 && a[j] > t; --j){
			a[j+1] = a[j];
		}
		a[j+1] = t;
		if(flag == true) return true;
	}
	return false;
}

int main(){
	freopen("1098.txt", "r", stdin);
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>heap[i];
		temp[i] = heap[i];
	}
	for(int i=1; i<=n; ++i){
		cin>>changed[i];
	}
	if(insertsort(temp)){
		cout<<"Insertion Sort"<<endl;
		for(int i=1; i<=n; ++i){	
			if(i!=1)
				cout<<" ";
			cout<<temp[i];
		}
	}else{
		heapsort();
		cout<<"Heap Sort"<<endl;
		for(int i=1; i<=n; ++i){	
			if(i!=1)
				cout<<" ";
			cout<<heap[i];
		}
	}

	return 0;
}