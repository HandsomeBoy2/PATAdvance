#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 1010;
stack <int> st;
int arr[maxn]; //保存题目出栈的序列 
int main(){
	int i, m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	while(k--){
		while(!st.empty()){
			st.pop();
		}
		for(i = 1; i <= n; i++){		
			scanf("%d", &arr[i]);
		}		
		int current = 1; //指向出栈序列中待出栈的元素 
		bool flag = true;
		for(i = 1; i <= n; i++){
			st.push(i);
			while(st.size() > m){
				flag = false;
				break;
			} 
			while(!st.empty() && st.top() == arr[current]){
				st.pop();
				current++;
			}
		}	
		if(st.empty() == true && flag == true)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

