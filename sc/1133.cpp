#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int addr, next, data;
}list[100010];
int main(){
	freopen("1133.txt", "r", stdin);
	int st, n,k;
	cin>>st>>n>>k;
	for(int i=0; i<n;++i){
		int ad,da,ne;
		cin>>ad>>da>>ne;
		list[ad].addr = ad;
		list[ad].data = da;
		list[ad].next = ne;
	}
	vector<Node> ans;
	for(int i=st; i!=-1; i=list[i].next){
		if(list[i].data<0)
			ans.push_back(list[i]);
	}
	for(int i=st; i!=-1; i=list[i].next){
		if(list[i].data>= 0 && list[i].data<=k)
			ans.push_back(list[i]);
	}
	for(int i=st; i!=-1; i=list[i].next){
		if(list[i].data>k)
			ans.push_back(list[i]);
	}
	for(int i =0; i<ans.size(); ++i){
		if(i!=0){
			printf("%05d\n%05d %d ", ans[i].addr, ans[i].addr, ans[i].data);
		}
		else
			printf("%05d %d ",ans[i].addr, ans[i].data);
	}
	cout<<-1;
	return 0;
}
