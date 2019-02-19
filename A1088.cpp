#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct Fraction{
	long int up;
	long int down;
};
long int gcd(long int a, long int b){
	return b == 0 ? a : (gcd(b, a % b));
}
struct Fraction reduction(struct Fraction result){
	if(result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
void showResult(struct Fraction r){
	reduction(r);
	if(r.up < 0) printf("(");
	if(r.down == 1) printf("%ld", r.up);
	else if(abs(r.up) > r.down && abs(r.up) % r.down != 0){
		printf("%ld %ld/%ld", r.up/r.down, abs(r.up)%r.down, r.down);
	} else if (abs(r.up) > r.down && abs(r.up) % r.down == 0){
			printf("%ld", r.up/r.down);
	}else{
		if(r.up == 0)
			printf("0");
		else 
			printf("%ld/%ld", r.up, r.down);
	}
	if(r.up < 0) printf(")");	
}
struct Fraction add(struct Fraction f1, struct Fraction f2){
	struct Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up*f2.down + f2.up*f1.down;
	return reduction(result);
}

struct Fraction minu(struct Fraction f1, struct Fraction f2){
	struct Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up*f2.down - f2.up*f1.down;
	return reduction(result);
}
struct Fraction multiply(struct Fraction f1, struct Fraction f2){
	struct Fraction result;
	result.down = f1.down * f2.down;
	result.up = f1.up*f2.up;
	return reduction(result);
}
struct Fraction except(struct Fraction f1, struct Fraction f2){
	struct Fraction result;
	result.down = f1.down * f2.up;
	result.up = f1.up*f2.down;	
	return reduction(result);
}
int main(){
	struct Fraction a, b;
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a, b));
	printf("\n");
	
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(minu(a, b));
	printf("\n");
	
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multiply(a, b));
	printf("\n");
	
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up != 0)
		showResult(except(a, b));
	else
		printf("Inf");
	printf("\n");
	return 0;
}

