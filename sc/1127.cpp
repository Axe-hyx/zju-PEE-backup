#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int > post, in, nodes[32];
void tra(int postr, int inl, int inr, int dep){
	if(inl > inr) return ;
	int i = inl;
	while(i<=inr && in[i]!= post[postr]) ++i;
	nodes[dep].push_back(post[postr]);
	tra(i-1 - inr + postr, inl, i -1, dep +1);
	tra(postr-1, i +1, inr, dep +1);
}
int main(){
	freopen("1127.txt", "r", stdin);
	int n,t;
	cin>>n;
	post.resize(n);
	in.resize(n);
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	for(int i=0; i<n; ++i){
		cin>>post[i];
	}
	tra(n-1, 0, n-1, 1);
	printf("%d", nodes[1][0]);
	for(int i= 2; i<32; ++i){
		if(i%2==0){
			for(int j = 0; j<nodes[i].size(); ++j){
				printf(" %d", nodes[i][j]);
			}
		}else{
			for(int j = nodes[i].size()-1; j>=0; --j){
				printf(" %d", nodes[i][j]);
			}
		}
	}
	return 0;
}
