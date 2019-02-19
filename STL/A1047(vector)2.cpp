#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cctype>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
using namespace std;
const int M = 40010;
vector<string> stu[M];
int main() {
	int i, j, n, k, c, course;
	string name;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++) {
		cin >> name >> c;
		for(j = 0; j < c; j++) {
			scanf("%d", &course);
			stu[course].push_back(name);
		}
	}
	for(i = 1; i <= k; i++) {
		printf("%d %d\n", i, stu[i].size());
		sort(stu[i].begin(), stu[i].end());
		for(j = 0; j < stu[i].size(); j++){
			cout << stu[i][j] << "\n";
		}
	}
	return 0;
}

