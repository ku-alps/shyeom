#include <iostream>
#include <math.h>
using namespace std;
void find(int row, int col, int start, int num); //ã�����ϴ� ��, ��, ���� ����, ���� ����

int main() {
	int num, row, col; //N, ����, �
	cin >> num >> row >> col;
	find(row, col, 0, pow(2, num));
}

void find(int row, int col, int start, int num){
	//�ڱ� ��ġ�� ���� ��
	if (num == 1) {
		cout << start;
		return;
	}
	//4������� ����� ����
	//ã�����ϴ� ��ġ�� ���� ��ġ�� ���ؿ��� ����
	int index = num / 2;
	if (row < index&&col < index)//���� ��
		find(row, col, start, index);
	else if (row < index && col >= index)//������ ��
		find(row, col-index, start + index * index, index);
	else if (row >= index && col < index)//���� �Ʒ�
		find(row-index, col, start + index * index*2, index);
	else if (row >= index && col >= index)//������ �Ʒ�
		find(row - index, col - index, start + index * index * 3, index);
}
