#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
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
int main(){
	int i, j, n, k;	
	char name[5];
	map <string, vector<int> > stu;
	scanf("%d%d", &n, &k);
	for(i = 0; i < k; i++){
		int course, x;
		scanf("%d%d", &course, &x);
		for(j = 0; j < x; j++){
			scanf("%s", name);
			stu[name].push_back(course);
		}
	}	
	for(i = 0; i < n; i++){
		scanf("%s", name);
		vector <int> temp = stu[name]; 
		printf("%s %d" , name, temp.size());
		sort(temp.begin(), temp.end());
		for(j = 0; j < temp.size(); j++){
			printf(" %d", temp[j]);
		}
		printf("\n");
	}
	return 0;
}

