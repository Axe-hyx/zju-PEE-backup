#include <iostream>
#include <cstring>
using namespace std;
int nxt[110];

// зЂвт nxt +1 
void getnext(char s[], int len){
	int j = -1;
	nxt[0] = -1;
	for(int i =1; i<len; ++i){
		while(j !=- 1 && s[i] != s[j+1]){
			j = nxt[j];
		}
		if(s[i] == s[j+1])
			++j;
		nxt[i] = j;
	}
}
int main(){
	//freopen("A.txt", "r", stdin);
	char a[110];
	int n;
	scanf("%s %d",a,&n);
	getnext(a, strlen(a));
	printf("%d", nxt[n-1] + 1);
	return 0;
}
