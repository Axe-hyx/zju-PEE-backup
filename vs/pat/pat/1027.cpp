#include "stdafx.h"


#include <iostream>

using namespace std;
char cha(int col){
	if(col < 10) return col+'0';
	return col -10 + 'A';
}
void deal(int col){
	if(col<12)
		printf("0%c",cha(col));
	else {
		string an;
		an+=cha(col/13);
		an+=cha(col%13);
		printf("%s", an.c_str());
	}
}
int main(){
	freopen("1027.txt","r", stdin);
	
	cout<<"#";
	
	int col;
	while(cin>>col){
		deal(col);
		char c =getchar();
		if(c=='\n'){
			cout<<endl;
			break;
		}
	}
	return 0;
}