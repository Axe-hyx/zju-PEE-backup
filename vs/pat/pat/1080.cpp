#include "stdafx.h"

#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct pes{
	int ge, gi;
	int al;
	int id;
	vector<int > wan;
};
bool cmp(pes &a, pes &b){
	if(a.al != b.al) return a.al > b.al;
	return a.ge > b.ge;
}
bool cmp2(pes &a, pes &b){
	return a.id < b.id;
}

int main(){
	freopen("1080.txt", "r", stdin);
	int n,m,k;
	int quora[110], cnt[110]={0};

	scanf("%d%d%d",&n,&m,&k);
	vector<pes> stu(n), sch[110];
	for(int i = 0; i< m; ++i){
		scanf("%d", &quora[i]);
	}
	
	for(int i=0;i<n;++i){
		struct pes p;
		scanf("%d%d",&p.ge, &p.gi);
		p.al = p.ge + p.gi;
		p.id = i;
		p.wan.resize(k);
		for(int j=0; j< k;++j){
			scanf("%d", &p.wan[j]);
		}
		stu.push_back(p);		
	}

	sort(stu.begin(), stu.end(), cmp);
	for(int i=0 ;i< n;++i){
		for(int j =0; j<k;++j){
			int id = stu[i].id;
			int cho = stu[i].wan[j];
			int last = cnt[cho] - 1;
			
			if(cnt[cho] < quora[cho] || ( last !=0 && stu[i].al == sch[cho][last].al&& stu[i].ge == sch[cho][last].ge )){
				sch[cho].push_back(stu[i]);
				cnt[cho]++;
				break;
			}
		}
	}
	for(int i=0;i<m;++i){
		sort(sch[i].begin(), sch[i].end(), cmp2);
		for(int j=0; j<sch[i].size(); ++j){
			if(j) printf(" ");
			printf("%d", sch[i][j].id);

		}
		printf("\n");
	}
	return 0;

	
	
}