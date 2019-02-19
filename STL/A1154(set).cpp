#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
struct edge{
	int node1;
	int node2;
};
int main(){
	int i, j, n, m, k, se;
	scanf("%d%d", &n, &m);
	struct edge edges[10002] = {0};
	int nodes[10002] = {0};
	for(i = 0; i < m; i++){
		scanf("%d%d", &edges[i].node1, &edges[i].node2);
	}
	scanf("%d", &k);
	for(i = 0; i < k; i++){
		set <int> s;
		bool flag = true;
		for(j = 0; j < n; j++){
			scanf("%d", &se);
			nodes[j] = se;
			s.insert(nodes[j]);
		}
		for(j = 0; j < m; j++){
			if(nodes[edges[j].node1] == nodes[edges[j].node2]){
				flag = false;
				break;
			}			
		}
		if(flag)
			printf("%d-coloring\n", s.size());
		else		
			printf("No\n");
	}	
	return 0;
}

