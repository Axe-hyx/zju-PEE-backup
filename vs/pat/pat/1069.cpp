#include "stdafx.h"

#include <cstdio>
#include <algorithm>
using namespace std;
int array[4];
bool cmp(int a, int b){
	return a>b;
}
void to_array(int number){
	for(int i =0; i<4; ++i){
		array[i] = number % 10;
		number /= 10;
	}
}
int to_number(int p[]){
	int sum = 0;
	for(int i =0; i<4; ++i){
		sum = 10 * sum + p[i];
	}
	return sum;
}
int main(){
	int t;
	scanf("%d", &t);
	while(1){
		to_array(t);
		sort(array, array+4, cmp);
		int b = to_number(array);
		sort(array, array +4);
		int a = to_number(array);
		t = b - a;
		printf("%04d - %04d = %04d\n", b, a, t);
		if(t == 0 || t == 6174)
			break;
	}
	return 0;
}
