#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct stu{
	string name;
	int online, mid, final, total;
};
bool cmp(stu a, stu b){
	if(a.total != b.total) return a.total > b.total;
	return a.name < b.name;
}
int main(){
	freopen("1137.txt", "r", stdin);
	int p,m,n;
	cin>>p>>m>>n;
	map<string, int > mp;
	vector<stu>ans;
	char name[22];
	int sco;
	for(int i=0; i<p; ++i){
		scanf("%s %d", name, &sco);
		if(sco >= 200){
			ans.push_back({name, sco, -1, -1, 0});
		}
		mp[name] = ans.size();
	}
	for(int i=0; i<m; ++i){
		scanf("%s %d", name, &sco);
		if(mp[name] == 0) continue;
		int id = mp[name] -1;
		ans[id].mid = sco;
	}
	for(int i=0; i<n; ++i){
		scanf("%s %d", name, &sco);
		if(mp[name] == 0) continue;
		int id = mp[name]-1;
		ans[id].final = sco;
		
		if(sco < ans[id].mid) ans[id].total= 
			(int)(0.5 + ans[id].mid * 0.4 + ans[id].final * 0.6);
		else ans[id].total = ans[id].final;
	}
	vector<stu> v;
	for(int i =0; i<ans.size(); ++i){
		if(ans[i].total >= 60){
			v.push_back(ans[i]);
		}
	}

	ans = v;
	sort(ans.begin(), ans.end(), cmp);
	for(int i =0; i<ans.size(); ++i){
		printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].online, ans[i].mid, ans[i].final,  ans[i].total);
	
	}
	return 0;
}
