#include <iostream>
#include <cstdio>
#include <cstring>
#include <string> 
using namespace std;
int book[10] = {0};
int main(){
	char num[22];
	scanf("%s", &num);
	int len = strlen(num);
	int i, temp = 0;
	bool flag = true;
	for(i = len-1; i >= 0; i--){
		book[num[i]-'0']++;
		temp = (num[i] - '0') * 2  + temp;
		num[i] = (temp % 10) + '0';
		book[temp%10]--;
		if(temp >= 10){
			temp = temp / 10;
		} else{
			temp = 0;
		}
	}
	for(i = 0; i < 10; i++){
		if(book[i] != 0) {
			flag = false;
			break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	if(temp > 0)
		printf("%c", temp+'0');
	printf("%s", num);
	return 0;
}

