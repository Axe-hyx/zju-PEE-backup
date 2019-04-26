#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
map <string, int>cnt;
const int sp = 'A' - 'a';
bool check(char c){
	if(c>='0' && c<='9') return true;
	if(c>='A' && c<='Z') return true;
	if(c>='a' && c<='z') return true;
	return false;
}
void tra(string &s){
	int sz = s.size();
	for(int i=0; i<sz; ++i){
		if(s[i]>='A' && s[i] <='Z') s[i] -= sp;
	}
}

int main(){
	string s;
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1071.txt", "r", stdin);

	getline(cin, s);
	int size = s.length();
	int p = 0;
	while(p< size){
		string word;
		while(p<size && !check(s[p]))++p;
		if(p>=size) break;
		int l = p;
		while(p<size && check(s[p])) ++p;
		word = s.substr(l, p-l);
		tra(word);
		//printf("%s\n", word.c_str());
		if(cnt.find(word) == cnt.end()){
			cnt[word] = 1;
		}else{
			++cnt[word];
		}
		
	}
	int max =0;
	string an;
	for(map<string, int>::iterator it= cnt.begin(); it!=cnt.end(); ++it){
		if(it->second > max){
			max = it->second;
			an = it->first;
		}
	}
	cout<<an<<" "<<max<<endl;
	return 0;
}