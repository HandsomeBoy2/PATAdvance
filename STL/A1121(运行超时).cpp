#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int main() {
	int i, j, n, m, num;
	int num1, num2;
	scanf("%d", &n);
	set <int> s[n];
	set <int> s1;
	for(i = 0; i < n; i++) {
		scanf("%d%d", &num1, &num2);
		s[i].insert(num1);
		s[i].insert(num2);
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++) {
		scanf("%d", &num);
		s1.insert(num);
	}
	int flag = 0;
	
	//50000*2*100  ÔËÐÐ³¬Ê±  
	for(i = 0; i < n; i++) {
		for(set<int>::iterator it = s[i].begin(); it != s[i].end(); it++) {
			if(s1.find(*it) != s1.end()) {
				flag++;
			} 
			if(flag == 2) {
				s1.erase(s[i].begin(), it);
			}
		}
		flag = 0;	
	}
	printf("%lu\n", s1.size());
	for(set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		if(it != s1.begin()) printf(" ");
		printf("%05d", *it);
	}
	return 0;
}

