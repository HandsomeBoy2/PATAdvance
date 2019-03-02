#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct node {
	char num[10];
	int time, status;
};
//比较车牌号，其次再比较time
int cmp(struct node car1, struct node car2) {
	if(strcmp(car1.num, car2.num) != 0)
		return strcmp(car1.num, car2.num) < 0;
	else
		return car1.time < car2.time;
}
//比较时间
int cmp1(struct node car1, struct node car2) {
	return car1.time < car2.time;
}
int main() {
	int i, j, n, k;
	scanf("%d%d\n", &n, &k);
	struct node car[n];
	//输入
	for(i = 0; i < n; i++) {
		char status[4];
		int hour, minute, second;
		scanf("%s %d:%d:%d %s\n", car[i].num, &hour, &minute, &second, status);
		car[i].time = hour*3600 + minute*60 + second;
		car[i].status = strcmp(status, "in") == 0 ? 1 : -1;
	}
	//验证输入
//	for(i = 0; i < n; i++){
//		cout << car[i].num << " " << car[i].time << " "<< car[i].status << endl;
//	}
	sort(car, car+n, cmp);
	vector <node> cars;
	map <string, int> parkingTime;
	int maxTime = -1;
	for(i = 0; i < n-1; i++) {
		if(strcmp(car[i].num, car[i+1].num) == 0 &&
		        car[i].status == 1 && car[i+1].status == -1) {
			cars.push_back(car[i]);
			cars.push_back(car[i+1]);
			parkingTime[car[i].num] += (car[i+1].time - car[i].time);
			if(parkingTime[car[i].num] > maxTime) {
				maxTime = parkingTime[car[i].num];
			}
		}
	}
	sort(cars.begin(), cars.end(), cmp1);
	vector <int> count(n);
	int tempIndex = 0;
	//算出当前下标记录的时间点的车辆数目
	for(i = 0; i < cars.size(); i++) {
		if(i == 0)
			count[i] += cars[i].status;
		else
			count[i] = count[i-1] + cars[i].status;
		//cout << count[i] << " ";
	}
	for(i = 0; i < k; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int tempTime = h * 3600 + m * 60 + s;
		for(j = tempIndex; j < cars.size(); j++) {
			if(cars[j].time > tempTime) {
				printf("%d\n", count[j-1]);
				break;
			} else if(j == cars.size()-1) {
				printf("%d\n", count[j]);
			}
		}
		tempIndex = j;
	}
	//遍历map<string, int> parkingTime
	for(map<string, int>::iterator it = parkingTime.begin(); it != parkingTime.end(); it++) {
		if(it->second == maxTime) {
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxTime/3600, (maxTime%3600)/60, maxTime%60);
	return 0;
}

