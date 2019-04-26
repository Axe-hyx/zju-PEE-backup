#include "stdafx.h"
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct windows{
	int endtime, poptime;
	queue<int >qu;
}win[20];
const int maxn = 1010;
int needtime[maxn], ans[maxn], n, m,k,q;

int convert2time(int hh, int mm){
	return hh * 60 + mm;
}
int main(){
	freopen("1014.txt", "r", stdin);
	cin>>n>>m>>k>>q;
	for(int i=0; i<k; ++i){
		cin>>needtime[i];
	}
	for(int i=0; i<n; ++i){
		win[i].endtime = convert2time(8, 0);
		win[i].poptime = convert2time(8, 0);
	}

	for(int i =0; i<min(n*m, k); ++i){
		win[i  % n].qu.push(i);
		win[i  %n].endtime +=needtime[i];
		if(i < n)
			win[i % n].poptime +=needtime[i];
		ans[i] = win[i%n].endtime;
	}
	for(int i =n*m; i<k; ++i){
		int no = -1, en= 0x3fffffff;
		for(int j=0; j<n; ++j){
			if( win[j].poptime<en){
				en = win[j].poptime;
				no = j;
			}
		}
		win[no].qu.pop();
		win[no].qu.push(i);
		win[no].poptime += needtime[win[no].qu.front()];
		win[no].endtime += needtime[i];
		ans[i] = win[no].endtime;
	}

	for(int i=0;i<q;++i){
		int t;
		cin>>t;
		if(ans[t-1]-needtime[t-1] >=convert2time(17,0)){
			cout<<"Sorry"<<endl;
		}else{
			printf("%02d:%02d\n", ans[t-1]/60, ans[t-1]%60);
		}
	}

	return 0;

}