#include "stdafx.h"

#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int main(){
	freopen("1051.txt", "r", stdin);
	int m,n,k;
	cin>>m>>n>>k;
	int che[1010], p=0;
	
	for(int i=0; i<k;++i){
		while(!st.empty()){
			st.pop();
		}
		for(int j=0; j<n;++j){
			cin>>che[j];		
		}
		
		int curr = 0;
		bool flag = true;
		for(int j =1; j<=n;++j){
			st.push(j);
			if(st.size() > m){
				flag = false;
				break;
			}
			while(!st.empty() && st.top()==che[curr]){
				st.pop();
				curr++;
			}
		}


		if(flag && st.empty())
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}


	return 0;
}	