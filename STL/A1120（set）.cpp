#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int getFriendNum(int num){
	int sum = 0;
	while(num != 0){
		int temp = num % 10;
		sum += temp;
		num /= 10;
	}
	return sum;
}
int main(){
	int i, n, num; 
	scanf("%d", &n);
	set <int> s;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		s.insert(getFriendNum(num));
	}
	printf("%d\n", s.size());
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		if(it != s.begin()) printf(" ");
		printf("%d", *it);
	}	
	return 0;
}

