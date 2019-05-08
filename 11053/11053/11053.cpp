#include <iostream>
using namespace std;

int cache[1010]; // 최대 길이수 저장
int arr[1010];

int check(int cnt);

void main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> arr[i];
		cache[i] = 0;
	}

	cout << check(cnt);
}

int check(int cnt) {
	int max = 0;
	//if (cache != 0)
	//	return max;
	int i = 0;
	for (int i = 0; i < cnt; i++) {
		int temp = 0;
		if (i == 0) {
			temp = 0;
		}
		else {
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && cache[j] > temp)
					temp = cache[j];
			}
		}
		cache[i] = temp + 1;
		if (cache[i] > max)
			max = cache[i];
	}
	return max;
}