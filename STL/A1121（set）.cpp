#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int main(){
	int i, n, m, a, b, join, couple[100010] = {0}, e[100010] = {0};
	scanf("%d", &n);
	set <int> s;
	for(i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d", &join);
		e[join] = 1;
		s.insert(join);
	}
	for(i = 0; i < 100000; i++){
		if(e[couple[i]] == 1 && e[couple[couple[i]]] == 1){
			s.erase(couple[i]);
			s.erase(couple[couple[i]]);
		}
	}
	printf("%d\n", s.size());
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		if(it != s.begin()) printf(" ");
		printf("%05d", *it);//输出要注意不足5位用0补齐  这儿是一个测试点 
	}
	return 0;
}

