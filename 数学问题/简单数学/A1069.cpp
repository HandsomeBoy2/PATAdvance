/*
1069 The Black Hole of Numbers £¨20 ·Ö£©
For any 4-digit integer except the ones with all the digits being the same, 
if we sort the digits in non-increasing order first, and then in non-decreasing order,
a new number can be obtained by taking the second number from the first one.
Repeat in this manner we will soon end up at the number 6174 -- the black hole of 4-digit numbers. 
This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range (0,10
?4
?? ).

Output Specification:
If all the 4 digits of N are the same, print in one line the equation N - N = 0000. 
Else print each step of calculation in a line until 6174 comes out as the difference.
 All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/


#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
void to_array(int n, int num[]){
	for(int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}
int to_int(int Max, int Min, int num[]){
	for(int i = 3; i >= 0; i--){
		Min *= 10;
		Min += num[i];
	}
	for(int i = 0; i < 4; i++){
		Max *= 10;
		Max += num[i];
	}
	if(Max == Min){
		printf("%d - %04d = %04d\n", Max, Min, Max-Min);
		return 0;
	} else{
		printf("%d - %04d = %04d\n", Max, Min, Max-Min);
		return 	Max-Min;
	}
}
int main(){
	int N, Max, Min;
	scanf("%d", &N);
	int num[5];
	
	
	while(1){
		Max = 0, Min = 0;
		to_array(N, num);
		sort(num, num+4, cmp);
		N = to_int(Max, Min, num);
		if(N == 0 || N == 6174){
			break;
		}
	}
	return 0;
}

