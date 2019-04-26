#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 输入不管精度 输出考虑 如果输入写成 .2lf 全错 
int main(){
	freopen("1108.txt", "r", stdin);
	int n;
	cin>>n;
	char buf[100];
	char def[100];
	double sum = 0.0;
	int cnt = 0;
	for(int i=0; i<n; ++i){
		scanf("%s", buf);
		double c;
		
		sscanf(buf,"%lf", &c);
		sprintf(def, "%.2f", c);
		bool flag = true;
		for(int i =0; i<strlen(buf);++i){
			//cout<<def[i]<<buf[i]<<endl;
			if(def[i] != buf[i]) {
				flag = false;
				break;
			}
		}
		if(flag == false || c < -1000 || c > 1000  ){
			printf("ERROR: %s is not a legal number\n", buf);
			continue;
		}else {
			sum += c;
			++cnt;
		
		
		}
	}
		if(cnt == 1){
			printf("The average of 1 number is %.2f\n", sum);
		}else if(cnt > 1)
		{
			printf("The average of %d numbers is %.2f\n", cnt , sum / cnt);
		}else
			printf("The average of 0 numbers is Undefined\n");
	return 0;
}
