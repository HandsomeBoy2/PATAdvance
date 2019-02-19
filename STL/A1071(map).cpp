#include<iostream>
#include<cstdio>
#include<string>
#include<cstring> 
#include<map>
using namespace std;
bool check(char c){
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= '0' && c <= '9') return true;
	return false;
}
int main(){
	int i, j;
	map <string, int> p;
	string s;
	getline(cin, s);
	int len = s.length();
	for(i = 0; i < len; i++){
		string str = ""; //初始化"" 否则一个测试点过不去 
		while(i < len && check(s[i])){
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a'; 
			str += s[i];
			i++;
		}
		if(str != ""){
			if(p.find(str) != p.end()) p[str]++;
			else p[str] = 1;
		} 
	}
	int ma = 0; 
	string ans;
	for(map<string, int>::iterator it = p.begin(); it != p.end(); it++){
		if(it->second > ma){
			ma = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << ma; 
	return 0;
}

