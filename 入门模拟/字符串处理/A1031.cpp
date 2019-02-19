#include<iostream>
#include<cstdio>
#include<string> 
using namespace std;
int main(){
//	9 / 3 = 3 ...0
//	10 / 3 = 3 ...1
//	11 / 3 = 3 ...2
	string s;
	cin >> s;
	int n = s.length();
	int left = n / 3;
	int bottom = n / 3 + n % 3;
	if(left == bottom){
		left -= 1;
		bottom += 2;
	}
	int i, j;
	for(i = 0; i < left; i++){
		cout << s[i];
		for(j = 0; j < bottom-2; j++){
			cout << ' '; 
		}
		cout << s[s.length()-i-1] << endl; 
	}
	for(i = 0; i < bottom; i++){
		cout << s[left+i];
	}
	return 0;
}

