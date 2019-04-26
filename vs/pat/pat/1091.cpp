#include "stdafx.h"


// bfs 和 dfs 区别
// bfs 找到可用元素时 立即vis = true 否则其他路径可能又经过该点
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int x[6] = {0, 0, 0, 0, 1, -1};
int y[6] = {0, 0, 1, -1, 0, 0};
int z[6] = {1, -1, 0, 0, 0, 0};


int sli[1290][130][61] = {0};
bool vis[1290][130][61];
int n,m,l,t, all=0;
bool judge(int i, int j, int k){
	if(i<0 || j<0 || k<0 || i>=n || j>=m || k >= l) return false;
	if(vis[i][j][k] == true || sli[i][j][k] == 0) return false;
	return true;
}
struct Node{
	int x,y,z;
};
// 一次bfs 寻找到该块全部元素，否则使用buttom up的方法 无法在有阈值的情况下返回
int bfs(int i, int j, int k){
	int cnt = 0;
	queue<Node> qu;
	struct Node no;
	no.x = i, no.y = j, no.z =k;
	qu.push(no);
	while(!qu.empty()){
		Node t = qu.front();
		qu.pop();
		int tx = t.x, ty = t.y, tz = t.z;
		++cnt;
		vis[i][j][k] = true;	
		for(int i=0; i<6; ++i){
			t.x = tx + x[i];
			t.y = ty + y[i];
			t.z = tz + z[i];
			if(judge(t.x, t.y, t.z)){
				qu.push(t);
				vis[t.x][t.y][t.z] = true;
			}
		}
	}
	
		
	if(cnt >= t)
		return cnt;
	else return 0;
}
int main(){
	freopen("1091.txt", "r", stdin);
	cin>>n>>m>>l>>t;
	for(int k =0; k<l; ++k){
		for(int i = 0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin>>sli[i][j][k];
			}
		}
	}

	memset(vis, 0,sizeof(vis));
	
	for(int k =0; k<l; ++k){
		for(int i = 0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(sli[i][j][k]!=0 && vis[i][j][k] == false){
	//				printf("%d %d %d\n",i,j,k);
					all += bfs(i, j, k);
				}
				
			}
		}
	}
	cout<<all<<endl;
	
	return 0;
}