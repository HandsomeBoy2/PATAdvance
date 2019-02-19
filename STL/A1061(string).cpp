#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string s1, s2, s3, s4;	
	cin >> s1 >> s2 >> s3 >> s4; 
	int len1 = s1.length() > s2.length() ? s1.length() : s2.length();
	int len2 = s3.length() > s4.length() ? s3.length() : s4.length();
	int i = 0, j = 0;
	char sameLetter[2];
	int position = 0;
	int m;
	string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	for(i = 0; i < len1; i++){
		if(s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')){
			sameLetter[0] = s1[i];
			j = i;
			break;
		}
	}
	for(i = j+1; i < len1; i++){
		if(s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || isdigit(s1[i]))){
			sameLetter[1] = s1[i];
			break;
		}
	}
	for(i = 0; i < len2; i++){
		if(s3[i] == s4[i] && isalpha(s3[i])){
			position = i;
			break;
		}
	}
	if(isdigit(sameLetter[1]))
		m = sameLetter[1]-'0';
	else
		m = sameLetter[1]-'A'+10;
	cout << weekday[sameLetter[0]-'A'];
	printf(" %02d:%02d", m, position);
	return 0;
}

