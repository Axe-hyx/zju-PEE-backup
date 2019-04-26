#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string getsum(string a, string b){
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	int len =0;
	for(int i =0; i<a.length() || i<b.length()||carry; ++i){
		int ca = a[i] ==0 ? 0: a[i] -'0';
		int cb = b[i] ==0? 0 : b[i] -'0';
		c += (ca + cb + carry) % 10 + '0';
		carry =  (carry + ca + cb) /10;
	}
	if(carry)
		c+='1';
	reverse(c.begin(),c.end());
	while(c.length() -1 >=1 && c[0] == 0)
		c.erase(c.begin());
	return c;
}
int main(){
	freopen("1136.txt", "r", stdin);
	string s, sum;
	cin>>s;
	int n=10;
	while(n--){
		string res = s;
		reverse(res.begin(),res.end());
		if(res == s) break;
		sum = getsum(s,res);
		
		cout<<s<<" + "<<res<<" = " << sum<<endl;
		s = sum;
		
		
	}
	if(n>0) cout<<s<<" is a palindromic number."<<endl;
	else cout<<"Not found in 10 iterations."<<endl;
	return 0;
}
