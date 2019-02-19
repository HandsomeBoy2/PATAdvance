#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main(){
//	1  2  3
//     5    4

//1 3 7 21 30
	int i, j, m, n, be, en, s1 = 0;
	scanf("%d", &n);
	int dis[n+1] = {0};
	for(i = 1; i <= n; i++){
		scanf("%d", &dis[i]);
		s1 += dis[i];	
		dis[i] = s1;
	}	
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d %d", &be, &en);
		if(be > en)
			swap(be, en);
		int s = 0;
		s = dis[en-1] - dis[be-1]; 
		s = s > (s1-s) ? (s1-s) : s;
		printf("%d\n", s);
	}
	return 0;
}

