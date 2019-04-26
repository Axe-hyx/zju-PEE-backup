#include "stdafx.h"

#include  <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100010
int dis[maxn];
typedef long long LL;
LL sum[maxn];
LL all = 0;
int main(){
	int n;
	freopen("1046.txt", "r", stdin);
	scanf("%d", &n);
	sum[0] = 0;
	for(int i=0; i<n; ++i){
		scanf("%d", &dis[i]);
		all += dis[i];
		if(i>0)
			sum[i] = sum[i-1] + dis[i-1];
	}

	scanf("%d", &n);
	int a,b;
	for(int i=0; i<n; ++i){
		scanf("%d%d", &a, &b);
		a--, b--;
		if(a<b)	swap(a,b);
		LL t = sum[a]-sum[b];

		printf("%lld\n", min(t, all - t));
	}
	


	return 0;
}
