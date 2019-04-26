#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

// dfs Ìõ¼þÐ´´í stop <minstp || stop == minstp && cnt < mintra !!!!!
const int maxn  =10010;
using namespace std;
struct node {
	int adv, line;
	bool operator <(const node & a) const {
		return a.adv < adv;
	}
};
vector< node > G[maxn];
vector<node> temp, ans;
bool vis[maxn] = {false};
#define INF 0x3fffffff
int n, snum, st, et, k, start, des, minstp = INF, mintra = INF;
void dfs(int root, int stop, int line) {
	if(root==des) {
		temp.push_back({root, line});
		int star = temp[0].line, cnt = 1;
		for(int i =0; i<temp.size(); ++i) {
			if(temp[i].line != star) {
				++cnt;
				star = temp[i].line;
			}
		}
		if(stop < minstp || (stop == minstp && cnt < mintra)) {
			minstp = stop;
			mintra = cnt;
			ans = temp;
		}
		temp.pop_back();
		return;
	}
	if(G[root].size() ==0 || stop > minstp) {
		return;
	}
	for(int i =0; i<G[root].size(); ++i) {
		if(vis[G[root][i].adv] == false) {
			temp.push_back({root,G[root][i].line});
			vis[G[root][i].adv] = true;
			dfs(G[root][i].adv, stop+1, G[root][i].line);
			vis[G[root][i].adv] = false;
			temp.pop_back();
		}
	}
}

int main() {
	freopen("1131.txt", "r", stdin);
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>snum>>st;
		for(int j=1; j<snum; ++j) {
			cin>>et;
			G[et].push_back({st, i});
			G[st].push_back({et, i});
			st = et;
		}
	}
	cin>>k;
	for(int i=0; i<k; ++i) {
		memset(vis, 0, sizeof(vis));
		minstp = INF;
		mintra = INF;
		cin>>start>>des;
		dfs(start,0, -1);
		cout<<minstp<<endl;
		int st = ans[0].line, sp = start;
		for(int i =0; i<ans.size(); ++i) {
			if(st != ans[i].line || i == ans.size()-1) {
				printf("Take Line#%d from %04d to %04d.\n", st, sp, ans[i].adv);
				st = ans[i].line;
				sp = ans[i].adv;
			}
		}
	}
}


