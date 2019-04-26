#include "stdafx.h"
// 全换成基本输出
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string , int> mp;
struct student {
	string id;
	int val; // for cmp
}stu[10010];
bool cmp(student a, student b){
	return a.val != b.val? a.val > b.val : a.id < b.id;
}
int n,m;
int main(){
	
	freopen("1153.txt", "r", stdin);
	
	
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		string s;
		cin>>s;
		stu[i].id =s;
		cin>>stu[i].val;
	}
	for(int i=0; i<m; ++i){
		string s;
		int cd;
		cin>>cd>>s;
		printf("Case %d: %d %s\n", i+1, cd, s.c_str());
		vector<student> ans;
		int sum =0, cnt =0;
		if(cd == 1){
			for(int i =0;i<n;++i){
				if(stu[i].id[0] == s[0]){
					ans.push_back(stu[i]);
				}	
			}	
		
		}else if(cd ==2){
			for(int j=0; j<n; ++j){
				if(stu[j].id.substr(1,3) == s){
					++cnt;
					sum+=stu[j].val;
				}
			}
			if(cnt)printf("%d %d\n", cnt, sum);
		}else {
			unordered_map<string, int>m;
			for(int j =0; j<n; ++j){
				if(stu[j].id.substr(4,6) == s){
					m[stu[j].id.substr(1,3)]++;
				}
			}
			for(unordered_map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
				student t;
				t.id = it->first;
				t.val = it->second;
				ans.push_back(t);
			}
		}
		
		sort(ans.begin(), ans.end(), cmp);
		
		for(int j=0;j<ans.size(); ++j){
			printf("%s %d\n", ans[j].id.c_str(), ans[j].val);
			
		}
	
		if(((cd ==1 || cd ==3)&& ans.size()==0) || (cd ==2 && cnt==0)){
			printf("NA\n");
			continue;
		}
		
		
	}
	return 0;

	
}
