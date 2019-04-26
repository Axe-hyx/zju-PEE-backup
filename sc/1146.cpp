#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("1146.txt", "r", stdin);
	int n, m, k,a ,b, in[1010];
	cin>>n>>m;
	vector<int > v [1010];
	for(int i =0; i<m; ++i){
		cin>>a>>b;
		v[a].push_back(b);
		++in[b];
	}
	cin>>k;
	bool out = false;
	for(int i=0; i<k; ++i){
		bool flag = true;
		vector <int> tem (in, in +1 +n);
		for(int j=0; j<n; ++j){
			cin>>a;
			if(tem[a]!=0) {
				flag = false;
				//cout<<a<<endl;
			}
			else for(int m =0; m < v[a].size(); ++m){
				--tem[v[a][m]];
			}
			
		}
		
		if(flag == true) continue;
		else {
			if(out) printf(" ");
			printf("%d", i);
		}	out = true;
	}
	
}
