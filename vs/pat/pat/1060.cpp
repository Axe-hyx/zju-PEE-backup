#include "stdafx.h"
// 注意对0的处理
// 根据零点决定左移右移 注意为0情况 最后根据数位补足或者裁剪
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int e;
string deal(string s, int &n){
	while(s[0] == '0'){
		s.erase(s.begin());
	}

	int k =0;
	int len = s.size();
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s[0] == '0'){
			s.erase(s.begin());
			--n;
		}
	}else{
		while(k<len && s[k]!='.'){
				++k;
				++n;
		}
		if(k < len){
			s.erase(s.begin()+k ); // delete '.'
		}
	}
	if(s.size() == 0){
		n = 0;
	}
	
	while(s.size()<e){ // add esp;
		s+='0';
	}
	
	return s.size() > e? s.substr(0, e):s ;
}
int main(){
	freopen("1060.txt", "r", stdin);
	string s1, s2;
	int e1 = 0,e2 =0;
	string s3, s4;
	cin>>e>>s1>>s2;
	s3 = deal(s1,e1);
	s4 = deal(s2,e2);
	
	
	if(s3 == s4 && e1 == e2){
		printf("YES 0.%s*10^%d\n", s3.c_str(), e1);
	}else{
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", s3.c_str(), e1, s4.c_str(), e2);
	}
	return 0;
}