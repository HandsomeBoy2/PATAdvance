#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n;
string deal(string s, int& e){
	int k = 0; //s���±�
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	} 
	if(s[0] == '.'){ //��ȥ��ǰ�������С���㣬��˵��s��С��1��С��
	    s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin()); //ȥ��С��������λǰ�������� 
			e--; //ÿȥ��һ��0��ָ��e��1	
		} 
	}else{
		while(k < s.length() && s[k] != '.'){ //Ѱ��С���� 
			k++;
			e++; //ֻҪ������С���㣬ָ����1 
		} 
		if(k < s.length()){ //while������ kС��s.length��˵��������С���� 
			s.erase(s.begin()+k);
		}
	}
	if(s.length() == 0){
		e = 0; //���ȥ��ǰ��0��s�ĳ���Ϊ0�������������0 
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
	int e1 = 0, e2 = 0; //e1��e2Ϊs1��s2��ָ�� 
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	
	if(s3 == s4 && e1 == e2){ //��������ͬ��ָ����ͬ���������YES�� 
		cout << "YES 0." << s3 << "*10^" << e1 << endl;  
	} else{
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
}

