#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n;
string deal(string s, int& e){
	int k = 0; //s的下标
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	} 
	if(s[0] == '.'){ //若去掉前导零后是小数点，则说明s是小于1的小数
	    s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin()); //去掉小数点后非零位前的所有零 
			e--; //每去掉一个0，指数e减1	
		} 
	}else{
		while(k < s.length() && s[k] != '.'){ //寻找小数点 
			k++;
			e++; //只要不遇到小数点，指数加1 
		} 
		if(k < s.length()){ //while结束后 k小于s.length，说明遇到了小数点 
			s.erase(s.begin()+k);
		}
	}
	if(s.length() == 0){
		e = 0; //如果去除前导0后s的长度为0，则这个数就是0 
	}
	int num = 0;
	k = 0;
	string res;
	while(num < n){
		if(k < s.length()) res += s[k++];
		else res += '0';
		num++;
	} 
	return res;
}

int main(){
	int e1 = 0, e2 = 0; //e1和e2为s1与s2的指数 
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	
	if(s3 == s4 && e1 == e2){ //若主体相同且指数相同，则输出‘YES’ 
		cout << "YES 0." << s3 << "*10^" << e1 << endl;  
	} else{
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
}

