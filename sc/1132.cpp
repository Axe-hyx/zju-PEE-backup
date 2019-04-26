#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		string s;
		cin>>s;
		int len = s.length();
		int a = stoi(s.substr(0,len/2));
		
		int b = stoi(s.substr(len/2,len/2));
		if(a * b == 0 || stoi(s) % (a * b) !=0) {
			cout<<"No";
		}else
			cout<<"Yes";
	}
	return 0;
}
