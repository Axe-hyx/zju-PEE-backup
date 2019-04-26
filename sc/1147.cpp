#include <iostream>
#include <vector>
// об╠Й 
using namespace std;
vector<int > ans;
int n,m;
int num[1010];
void tra(int root){
	if(root > m) return;
	tra(root * 2);
	tra(root * 2 + 1);
	ans.push_back(num[root]);
}
int main(){
	freopen("1147.txt", "r", stdin);
	cin>>n>>m;
	
	
	for(int i =0; i<n; ++i)	{
		int flag= 1;
		for(int j =1; j<=m; ++j)	{
			cin>>num[j];
		}
		if(m > 1 ){
			if(num[1] > num[2]) flag= 1;
			else flag = -1;
		} 
		for(int j = 1; j<=m/2; ++j){
			int l = j *2;
			
			if(flag == 1 && (num[j] < num[l] || (l+1 <=m && num[j] < num[l+1])) ) flag = 0;
			if(flag == -1 && (num[j] > num[l] || (l+1 <=m && num[j] > num[l+1]))) flag = 0; 
		}
		if(flag ==1)printf("Max Heap\n");
		else if(flag== -1) printf("Min Heap\n");
		else printf("Not Heap\n");
		ans.clear();
		tra(1);
		for(int j=0; j<m; ++j){
			if(j!= 0)
				printf(" ");
			printf("%d", ans[j]);
		}
		printf("\n");
		
	}
	
	return 0;
}
