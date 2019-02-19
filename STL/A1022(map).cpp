#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<map>
using namespace std;
void query(map<string, set<int> > &p, string &str){
	if(p.find(str) == p.end()) printf("Not Found\n");
	else{
		for(set<int>::iterator it =  p[str].begin(); it != p[str].end(); it++){
			printf("%07d\n", *it);
		}
	}
}
int main(){
	int i, m, n, id;
	scanf("%d", &n);	
	string title, author, keyWord, publisher, publishedYear;
	map <string, set<int> > pTitle, pAuthor, pKeyWord, pPublisher, pPublishedYear;
	for(i = 0; i < n; i++){
		cin >> id;
		char c = getchar();
		getline(cin, title);
		pTitle[title].insert(id);
		getline(cin, author);
		pAuthor[author].insert(id);
		while(cin >> keyWord){
			pKeyWord[keyWord].insert(id);
			c = getchar();
			if (c == '\n') 
				break;
		} 
		getline(cin, publisher);
		pPublisher[publisher].insert(id);
		getline(cin, publishedYear);
		pPublishedYear[publishedYear].insert(id);	
	}
	int type;
	string str;
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d: ", &type); 
		getline(cin, str);
		cout << type << ": " << str << endl;
		if(type == 1) query(pTitle, str);
		if(type == 2) query(pAuthor, str);
		if(type == 3) query(pKeyWord, str);
		if(type == 4) query(pPublisher, str);
		if(type == 5) query(pPublishedYear, str);
	}	
	return 0;
}

