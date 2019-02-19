#include<iostream>
#include<cstdio>
#include<cstring>
#include<string> 
#include<map>
using namespace std;
//0-12�Ļ�����
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
//13��[0,12]���Ļ�����
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170]; //��������ת���ɻ����� 
map <string, int> strToNum; //������ת���ɵ������� 
void init(){
	int i, j;
	//0-12 13�ı��� 
	//13�ı��������û�и�λ 
	for(i = 0; i < 13; i++){ 
		numToStr[i] = unitDigit[i]; //��λ[0,12] ��ʮλΪ0 
		strToNum[unitDigit[i]] = i; 
		numToStr[i*13] = tenDigit[i];//ʮλ[0,12] ����λΪ0
		strToNum[tenDigit[i]] = i * 13;
//		cout << i << " " << i*13 << endl; 
	}
	//��13��ʼ ����13�ı����� 
	for(i = 1; i < 13; i++){
		for(j = 1; j < 13; j++){
			string str = tenDigit[i] + " " + unitDigit[j]; //������ 
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
		if(s[0] >= '0' && s[0] <= '9'){ //����������� 
			int num = 0; 
			for(j = 0; j < s.length(); j++){
				num = num * 10 + (s[j] - '0');
			}
			cout << numToStr[num] << endl;
		} else{ //������ǻ����� 
			cout << strToNum[s] << endl; 
		}
	} 
	return 0;
}

