#include<iostream>
#include<cstdio>
#include<cstring>
#include<string> 
#include<map>
using namespace std;
//0-12的火星文
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
//13的[0,12]倍的火星文
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170]; //地球数字转换成火星文 
map <string, int> strToNum; //火星文转换成地球数字 
void init(){
	int i, j;
	//0-12 13的倍数 
	//13的倍数输出的没有个位 
	for(i = 0; i < 13; i++){ 
		numToStr[i] = unitDigit[i]; //个位[0,12] ，十位为0 
		strToNum[unitDigit[i]] = i; 
		numToStr[i*13] = tenDigit[i];//十位[0,12] ，个位为0
		strToNum[tenDigit[i]] = i * 13;
//		cout << i << " " << i*13 << endl; 
	}
	//从13开始 不是13的倍数的 
	for(i = 1; i < 13; i++){
		for(j = 1; j < 13; j++){
			string str = tenDigit[i] + " " + unitDigit[j]; //火星文 
			numToStr[i*13+j] = str;
			strToNum[str] = i*13+j; 
//			cout << i*13+j << endl; 
 		} 
	}	
}
int main(){
	init(); 
	int i, j, n;
	scanf("%d%*c", &n);
	for(i = 0; i < n; i++){
		string s;
		getline(cin, s);
		if(s[0] >= '0' && s[0] <= '9'){ //输入的是数字 
			int num = 0; 
			for(j = 0; j < s.length(); j++){
				num = num * 10 + (s[j] - '0');
			}
			cout << numToStr[num] << endl;
		} else{ //输入的是火星文 
			cout << strToNum[s] << endl; 
		}
	} 
	return 0;
}

