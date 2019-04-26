#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int > ans, temp,c;
int n, p, k;
int maxfs = -1;
void init(){
	int t =0, cnt = 1;;
	while(t<=n){
		c.push_back(t);
		t = pow(cnt,p);
		++cnt;
	}
}
void dfs(int index, int tsum, int tk, int fsum){
	if(tsum >= n ){
		if(tk == k && fsum > maxfs){
			maxfs = fsum;
			ans = temp;
		}
		return ;
	}
	while(index >=1){
		if(tk < k && tsum + c[index] <=n ){
			temp[tk] = index;
			dfs(index, tsum+c[index], tk+1, fsum + index);
		}
		--index;
	}
}
int main(){
	freopen("1103.txt", "r", stdin);
	cin>>n>>k>>p;
	temp.resize(k);
	init();
	dfs(c.size()-1, 0, 0, 0);
	
	if(ans.size()== 0) printf("Impossible\n");
	else{
		printf("%d = ", n);
		for(int i =0; i<ans.size(); ++i){
			if(i!=0)
				printf(" + ");
			printf("%d^%d", ans[i], p);
		}
		printf("\n");
	}
	return 0;
}
