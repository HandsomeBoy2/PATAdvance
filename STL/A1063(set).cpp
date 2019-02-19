#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N = 51;
set <int> s[N];
void cmp(int x, int y){
	int totalNum = s[y].size(), sameNum = 0;
	for(set<int>::iterator it = s[x].begin(); it != s[x].end(); it++){
		if(s[y].find(*it)!= s[y].end()) sameNum++;
		else totalNum++;
	}
	printf("%.1f%\n", sameNum * 100.0/ totalNum);
	return;
}
int main(){
	int i, j, n, m, num, k, q1, q2;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &m);
		for(j = 0; j < m; j++){
			scanf("%d", &num);
			s[i].insert(num);
		}
	}
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		scanf("%d%d", &q1, &q2);
		cmp(q1, q2);
	}
	return 0;
}

