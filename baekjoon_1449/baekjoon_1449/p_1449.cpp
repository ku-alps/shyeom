#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//입력
	int leak_num, length; // 새는 곳의 수, 테이프 길이
	int *leak_pos; // 새는 곳 위치 저장
	cin >> leak_num >> length;
	leak_pos = new int[leak_num];
	for (int i = 0; i < leak_num; i++) {
		cin >> leak_pos[i];
	}

	//크기 순서에 따라 오름차순으로 정렬
	sort(leak_pos, leak_pos + leak_num);

	double last_pos = 0; // 테이프의 끝 위치
	int count = 0; //쓴 테이프 수
	for (int i = 0; i < leak_num; i++) {
		if ((double)leak_pos[i] + 0.5 > last_pos) { //만약 새는 파이프의 끝까지 못 붙였다면
			last_pos = max(leak_pos[i] - 0.5 + length, last_pos + length); // 새로운 위치부터 붙이거나 이어서 붙이거나
			count++; //테이프 수++
		}
	}

	//결과출력
	cout << count;

	return 0;
}