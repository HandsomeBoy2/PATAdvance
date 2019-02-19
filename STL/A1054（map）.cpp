#include<iostream>
#include<cstdio>
#include<cstring>
#include<string> 
#include<map>
using namespace std;

int main(){
	int i, m, n, num;
	scanf("%d%d", &m, &n);
	int count = m*n;
	map <int, int> p; 
	for(i = 0; i < count; i++){
		scanf("%d", &num);
		p[num]++;
//		if(p.find(num) != p.end()) p[num]++;
//		else p[num] = 1;
	}
	int k, ma = 0;
	for(map<int, int>::iterator it = p.begin(); it != p.end(); it++){
		if(it->second > ma){
			ma = it->second;
			k = it->first;
		}
	}
	printf("%d", k);
	return 0;
}

