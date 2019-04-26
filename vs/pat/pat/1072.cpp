#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#define INF 0x3fffffff
const int maxn = 1020;
bool vis[maxn] = {false};
int G[maxn][maxn], d[maxn], mind = -1, n,m, k, ds;
void dij(int s){
	memset(vis, false, sizeof(vis));
	fill(d, d+maxn, INF);
	d[s] = 0;
	for(int i =1; i<=n+m; ++i){
		int u =-1, mins = INF;
		for(int j =1; j<=n+m; ++j){
			if(vis[j]  == false && d[j] < mins){
				mins = d[j];
				u =j;
			}
		}
		if(u == -1) return ;
		vis[u]  =true;
		for(int v= 1; v<=m+n; ++v){
			if(vis[v]== false && G[u][v] != INF){
				if(d[v] > d[u] + G[u][v])
					d[v] = d[u] + G[u][v];
			}
		}
	}
}
int main(){
	freopen("1072.txt", "r", stdin);
	cin>>n>>m>>k>>ds;
	fill(G[0], G[0] + maxn* maxn, INF);
	for(int i=0;i<k;++i){
		string a,b;
		int len, st, nd;
		cin>>a>>b>>len;
		if(a[0] == 'G'){
			a.erase(a.begin());
			st = stoi(a) + n;
		}else
			st = stoi(a);
		if(b[0] == 'G'){
			b.erase(b.begin());
			nd = stoi(b) + n;
		}else
			nd = stoi(b);
		G[st][nd] = len;
		G[nd][st] = len;	

	}

	double aavg= INF;
	int mmins = -1, anode = -1;
	for(int i=n+1;i<=m+n; ++i){
		dij(i);
		bool flag = false;
		double avg = 0.0;
			int mins = INF;
		for(int j =1; j<=n; ++j){
			if(d[j] > ds){
				flag = true;
				break;
			}
			if(d[j] < mins)
				mins = d[j];
			avg += d[j];
			
		}
		if(flag) continue;
		avg /= n;
		if(mins > mmins){
			mmins = mins;
			aavg = avg;
			anode = i;
		}else if(mins == mmins && aavg > avg){
			aavg = avg;
			anode = i;
		}
		
	}
	if(anode == -1)
		cout<<"No Solution"<<endl;
	else {
		cout<<"G"<<anode-n<<endl;
		printf("%.1lf %.1lf", (double)mmins, aavg);
	}
	return 0;
}