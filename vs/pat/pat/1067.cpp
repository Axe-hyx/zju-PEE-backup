#include "stdafx.h"


// ���һ��swap ��������������Ԫ��λ�� left ������Ϊ n-1
// ע��while ִ�� left �Σ� forѭ��ÿ����ͷö�� 10^ 10 ƽ�������Ӷȣ�tle
// �����������ʣ�ÿ���ҵ�k���ó�����ʱ��

#include <iostream>
using namespace std;
int t[100010];
int main(){
	freopen("1067.txt", "r", stdin);
	int n, left, tmp;
	cin>>n;
	left = n-1;
	
	for(int i=0; i<n; ++i){
		cin>>tmp;
		t[tmp] = i;
		if(tmp != 0 && i==tmp) --left;
	}

	int ans = 0;

	int k = 1;
	while(left >0){
		if(t[0] == 0){
			for(;k<n;){
				if(t[k] != k){
					++ans;
					swap(t[k],t[0]);
					break;
				}
				++k;
			}
		}
		while(t[0] != 0){
			swap(t[0],t[t[0]]);
			--left;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}