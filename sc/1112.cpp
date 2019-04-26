#include <iostream>
#include <map>
#include <string>
#include <set>

// 字符串最后插入多余字符 避免特判
// 统计每次出现是否k次倍数， 若否 置false 
using namespace std;
int main(){
	freopen("1112.txt", "r", stdin);
	int k;
	cin>>k;
	string s;
	cin>>s;
	s += '#';
	map<char , bool> mp;
	bool no[128]  = {false};
	int pre = 0, cnt =0;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == s[pre]){
			++cnt;
		}else{
			if(cnt % k!=0){
				no[s[pre]] = true;
			}
			cnt = 1;
			
		}
		mp[s[i]] = cnt % k == 0;
		pre = i;
		
	}
	for(int i= 0; i<128; ++i){
		if(no[i]) mp[i] = false;
	}
	set<char> st;
	
	for(int i =0; i<s.length()-1; ++i){
		if(st.count(s[i])==0 && mp[s[i]] == true){
			printf("%c",s[i]);
		}
		st.insert(s[i]);
	}
	printf("\n");
	for(int i=0; i<s.length()-1; ++i){
		printf("%c", s[i]);
		if(mp[s[i]] == true){
			i = i + k -1;
		} 
	}
	return 0;
}
