#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main(){
	int i, j, n, count = 0;
	scanf("%d", &n);
	vector <string> v;
	string name, pwd;
	for(i = 0; i < n; i++){
		cin >> name >> pwd;
		int len = pwd.length();
		bool flag = false;
		for(j = 0; j < len; j++){
			switch(pwd[j]){
				case '1': pwd[j] = '@'; flag = true; break;
				case '0': pwd[j] = '%'; flag = true;break;
				case 'l': pwd[j] = 'L'; flag = true; break;
				case 'O': pwd[j] = 'o'; flag = true; break;
			}
		}
		if(flag){
			string temp = name + " " + pwd;
			v.push_back(temp);
		}
	}
	count = v.size();
	if(count == 0){
		if(n == 1){
		   printf("There is 1 account and no account is modified");
		} else{
		   printf("There are %d accounts and no account is modified", n);
		}	
	} else{
		printf("%d\n", count);
		for(i = 0; i < count; i++){
			cout << v[i] << endl;
		}
	}
	return 0;
}

