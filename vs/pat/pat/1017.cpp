#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxk= 110;
struct customer{
	int needtime, servertime;
}usr[maxn];
int convert2time(int hh, int mm, int ss){
	return ss + mm * 60 + hh *3600;
}
bool cmp(customer a, customer b){
	if(a.servertime != b.servertime) return a.servertime < b.servertime;
	return a.needtime < b.needtime;
}
int cnt=0,n,k, endtime[maxk], ans[maxn] = {0};
int main(){
	freopen("1017.txt", "r", stdin);
	cin>>n>>k;
	for(int i =0; i<n; ++i){
		int hh,mm,ss, len;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &len);
		int at = convert2time(hh, mm, ss);
		if(at > convert2time(17,0,0)) continue;
		usr[cnt].servertime = at;
		usr[cnt++].needtime = len*60;

	}

	sort(usr, usr+cnt,cmp);
	int sum =0;
	for(int i=0; i<k; ++i){
		endtime[i] = convert2time(8,0,0);
	}
	for(int i=0; i<cnt; ++i){
		int u =-1, mins = 0x3ffffff;
		for(int j=0; j<k; ++j){
			if(endtime[j] < mins){
				mins = endtime[j];
				u = j;
			}
		}
		
		if(endtime[u] <= usr[i].servertime){
			endtime[u] = usr[i].servertime + usr[i].needtime;

		}else{
			endtime[u] += usr[i].needtime;
		}
		
		ans[i] = endtime[u]-usr[i].needtime - usr[i].servertime;
		sum +=ans[i];
	}
	printf("%.1f", (float) sum /cnt/60);
	

	
}