#include <iostream>
using namespace std;
int c[4];
string out = "OUT";
string in = "IN";
void reverse(int x){
	for(int i=0; i<4; ++i){
		if(i!=x) c[i] = 1 -c[i];
	}
}
bool finish(){
	return (c[1]==0 && c[2]==0 && c[3]==0 &&c[0]==0);
}
void pri(){
	for(int i=0; i<4; ++i){
		if(i!=0)
			printf(" ");
		printf("%s",  (c[i] == 1? out.c_str() : in.c_str()));
	}
	printf("\n");
}
int main(){
	//freopen("3.txt", "r", stdin);
	string s;
	for(int i =0; i<4; ++i){
		cin>>s;
		if(s=="IN")
			c[i] = 0;
		else c[i] = 1;
	}
	getchar();
	if(finish()) {
			printf("YES");
			return 0;
		}
	int k;
	cin>>k;
	for(int i =0; i<k; ++i){
		cin>>s;
		if(s=="UP"){
			reverse(2);
		}else if(s== "RIGHT"){
			reverse(3);
		}else if(s== "DOWN"){ 
			reverse(0);
		}else if(s=="LEFT"){
			reverse(1);
		}
		pri();
		if(finish()) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	
	return 0;
}
