#include <iostream>
using namespace std;
int main(){
	freopen("test.txt", "r", stdin);
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%05d %05d", a, b);
	return 0;
}
