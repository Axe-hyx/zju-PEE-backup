#include <iostream>
#include <unordered_map>
#include <string>
using namespace  std;
const int maxn = 1010;
unordered_map<string, int> mp;
string ton[maxn];
int m,n,s,cnt=0;
int main(){
	//freopen("1124.txt", "r", stdin);
	cin>>m>>n>>s;
	string name;
	bool flag = true;
	for(int i=1;i<=m;++i){
		cin>>name;
		if(mp.count(name)!=0) s = s+1;
		if(i==s && mp.count(name)==0){
			s = s+n;
			mp[name] = 1;
			printf("%s\n", name.c_str());
			flag = false;
		}
	}
	if(flag)printf("Keep going...");
		
	
		
	return 0;
}
