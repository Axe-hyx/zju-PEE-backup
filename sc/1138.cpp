#include <iostream>
#include <vector>
using namespace std;
vector<int >pre, in;
bool flag = false;

void postorder(int prel,int inl, int inr){
	if(inl > inr || flag == true) return;
	int i = inl;
	while(in[i]!=pre[prel]) ++i;
	postorder(prel+1, inl, i-1);
	postorder(prel +1 + i - inl, i+1, inr);
	if(flag == false){
		flag = true;
		cout<<pre[prel];
	}
}
int main(){
	freopen("1138.txt", "r", stdin);
	int n,t;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>t;
		pre.push_back(t);
	}
	for(int i=0; i<n; ++i){
		cin>>t;
		in.push_back(t);
	}
	postorder(0, 0, n-1);
	
	return 0;
}
