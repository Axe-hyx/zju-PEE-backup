#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

//重载set运算符 比sort函数更快 

struct no{
	int data, ref;
	bool operator < (const no &a)const{
		return (a.ref != ref)? ref > a.ref : data < a.data;
	}
};
unordered_set<int> st;
vector<no> sys;
int rec [50010];
bool cmp(no a, no b){
	if(a.ref != b.ref) return a.ref > b.ref;
	return a.data < b.data;
}

int main(){
	freopen("1129.txt", "r", stdin);
	int n,k,t;
	scanf("%d %d", &n, &k);
	set<no> st;
	for(int i =1; i<=n; ++i){
		scanf("%d", &t);
		
		if(i!=1){
			int cnt = 0;
			printf("%d:", t);
			for(auto it = st.begin(); cnt < k && it!=st.end(); ++it,++cnt){
				printf(" %d", *it);
			}
			printf("\n", t);
		}
		auto it=st.find({t, rec[t]});
		if(it != st.end()) st.erase(it);
		st.insert({t,++rec[t]});
	}
	/*
	freopen("1129.txt", "r", stdin);
	int n,k,t;
	scanf("%d %d", &n, &k);
	for(int i = 1;i<=n;++i){
		scanf("%d", &t);
		if(i!=1){
			printf("%d:", t);
			for(int i=0; i<min((int)sys.size(), k); ++i){
				printf(" %d", sys[i].data);
			}
			printf("\n");
		}
		
		if(st.count(t) ==0){
			st.insert(t);
			no node;
			node.data = t;
			node.ref = 1;
			sys.push_back(node);
		}else {
			int j =0;
			while(j<sys.size() && sys[j].data !=t) ++j;
			++sys[j].ref;
				
			
		}
		sort(sys.begin(), sys.end(),cmp);
		
	}
	return 0;
	*/
} 
