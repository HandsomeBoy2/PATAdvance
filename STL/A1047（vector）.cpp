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
const int maxn = 40010; //学生人数 
const int maxc = 2510;	//最大课程门数 
char name[maxn][5];
vector <int> course[maxc];  //course存放第i门课的所有学生编号

bool cmp(int a, int b){
	return strcmp(name[a], name[b]) < 0;
} 
int main(){
	int i, j, n, k, c, courseId;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++){
		scanf("%s %d", name[i], &c);
		for(j = 0; j < c; j++){
			scanf("%d", &courseId);
			course[courseId].push_back(i);
		}
	}
	
	for(i = 1; i <= k; i++){
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(j = 0; j < course[i].size(); j++){
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}

