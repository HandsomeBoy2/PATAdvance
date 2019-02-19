//如果使用二位数组存放学生所选的课程号，会导致内存超限。因此要用vector
//用map<string, vector<int> > 会导致时间过长，因为map的查询复查度为nlogn
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

const int M = 26*26*26*10 + 1;
vector <int> stu [M];

int getId(char name[]){
	int i, id = 0;
	for(i = 0; i < 3; i++){
		id = id * 10 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
int main(){
	int i, j, n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for(i = 0; i < k; i++){
		int course, x;
		scanf("%d%d", &course, &x);
		for(j = 0; j < x; j++){
			scanf("%s", name);
			int id = getId(name);
			stu[id].push_back(course);
		}
	}
	
	for(i = 0; i < n; i++){
		scanf("%s", name);
		int id = getId(name);
		sort(stu[id].begin(), stu[id].end());
		printf("%s %d" , name, stu[id].size());
		for(j = 0; j < stu[id].size(); j++){
			printf(" %d", stu[id][j]);
		}
		printf("\n");
	}
	return 0;
}

