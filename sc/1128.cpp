#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int col[1010];

// ¼ò»¯Âß¼­ 
int main(){
	freopen("1128.txt", "r", stdin);
	int n,t,r;
	
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t;
		bool flag = true;
		for(int j =0; j<t; ++j){
			cin>>col[j];
			for(int k=0; k<j; ++k){
				if(col[k] == col[j] || abs(j-k) == abs(col[j]-col[k])){
					
					flag = false;
					break;
				}
			}
		}
		cout<<(flag==true? "YES" : "NO")<<endl;
	}
}
