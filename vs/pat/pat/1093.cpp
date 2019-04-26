#include "stdafx.h"
#include <iostream>
#include <string>
#define debug(x) cout<<#x<<" -> "<<x<<endl
using namespace std;
typedef long long LL;
int main(){
	string s;
	cin>>s;
	
	LL sum =0;
	int cp = 0, ct = 0; // ct ”“±ﬂ”–∂‡…Ÿ
	for(int i =0; i<s.length(); ++i){
		if(s[i] == 'T') ++ct;
	}
	
	for(int i =0; i < s.length(); ++i){
		if(s[i] == 'P') ++cp;
		else if(s[i] == 'T') --ct;
		else sum += ct * cp;

	}
	printf("%d\n", sum %1000000007);
}