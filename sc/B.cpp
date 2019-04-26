#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e6 +10;
struct Link{
	int addr, data, next;
}link[maxn];
vector<Link> fir, se;
int main(){
	freopen("B.txt", "r", stdin);
	int num, st;
	cin>>num>>st;
	if(st == -1){
		printf("0 -1\n");
		return 0;
	}
	for(int i =0; i<num; ++i){
		int addr, da, ne;
		cin>>addr>>da>>ne;
		link[addr].data = da;
		link[addr].next= ne;
		link[addr].addr= addr;
	}
	int i= st;
	int cnt = 0;
	while(i != -1){
		i = link[i].next;
		++cnt;
	}
	i= st, num = cnt % 2==0 ? 1:0;
	while(i != -1){
		if(num <= cnt /2){
			fir.push_back(link[i]);
		}else 
			se.push_back(link[i]);
		i = link[i].next;
		++num;
	}
	vector<Link> ans;
	reverse(se.begin(), se.end());
	int l =0, r = 0;
	
	for(int i = 0; i<cnt; ++i){
		if(i %2 == 0){
			ans.push_back(fir[l++]);
		}else 
			ans.push_back(se[r++]);
			
	}
	if(ans.size()!=0){
		printf("%d %05d\n", cnt, ans[0].addr);
		for(int i =0; i<cnt; ++i){
			if(i==0) printf("%05d %d ", ans[i].addr, ans[i].data);
			else printf("%05d\n%05d %d ", ans[i].addr, ans[i].addr, ans[i].data);
		}
		printf("-1\n");
	}
	
	return 0;
}
