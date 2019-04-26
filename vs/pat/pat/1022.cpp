#include "stdafx.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdio>
using namespace std;

map<string, set<int>> title, author, keywords, pub, year;

void query(map<string, set<int>> &mp, string &s){
	if(mp.find(s)== mp.end()) cout<<"Not Found"<<endl;
	else
		for(set<int>::iterator it = mp[s].begin(); it!=mp[s].end();++it){
			printf("%07d\n", *it);
		}
}
int main(){
	freopen("1022.txt", "r", stdin);
	int n;
	cin>>n;
	while(n--){
		int no;
		string t,a,k,p,y;
		cin>>no;
		getchar();
		getline(cin, t);
		title[t].insert(no);
		getline(cin,a);
		author[a].insert(no);
		while(cin>>k){
			keywords[k].insert(no);
			char c = getchar();
			if(c=='\n') break;
		}
		getline(cin,p);
		pub[p].insert(no);
		getline(cin,y);
		year[y].insert(no);

	}
	cin>>n;
	while(n--){
		int type;
		scanf("%d: ", &type);
		string key;
		getline(cin, key);
		cout<<type<<": "<<key<<endl;
		switch(type){
		case 1:
			query(title, key);
			break;
		case 2:
			query(author, key);
			break;
		case 3:
			query(keywords, key);
			break;
		case 4:
			query(pub, key);
			break;
		case 5:
			query(year, key);
			break;
		default:
				break;
		}
	}

	
	return 0;
}