#include <iostream>
#include <math.h>
using namespace std;
void find(int row, int col, int start, int num); //찾고자하는 행, 열, 시작 숫자, 가로 개수

int main() {
	int num, row, col; //N, 몇행, 몇열
	cin >> num >> row >> col;
	find(row, col, 0, pow(2, num));
}

void find(int row, int col, int start, int num){
	//자기 위치에 왔을 때
	if (num == 1) {
		cout << start;
		return;
	}
	//4등분으로 나누어서 생각
	//찾고자하는 위치를 나눈 위치의 기준에서 생각
	int index = num / 2;
	if (row < index&&col < index)//왼쪽 위
		find(row, col, start, index);
	else if (row < index && col >= index)//오른쪽 위
		find(row, col-index, start + index * index, index);
	else if (row >= index && col < index)//왼쪽 아래
		find(row-index, col, start + index * index*2, index);
	else if (row >= index && col >= index)//오른쪽 아래
		find(row - index, col - index, start + index * index * 3, index);
}
