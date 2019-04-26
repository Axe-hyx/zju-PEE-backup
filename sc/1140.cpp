#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("1140.txt", "r", stdin);
	string s;
	int n;
	cin>>s>>n;
	while(--n){
		string t;
		for(int i=0; i<s.length(); ){
			int j = i;
			while(j<s.length() && s[i] == s[j]) ++j;
			t+=s[i] + to_string(j-i);
			i = j;
		}
		s= t;
	}
	cout<<s;
}

