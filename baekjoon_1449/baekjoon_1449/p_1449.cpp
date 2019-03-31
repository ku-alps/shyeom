#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//�Է�
	int leak_num, length; // ���� ���� ��, ������ ����
	int *leak_pos; // ���� �� ��ġ ����
	cin >> leak_num >> length;
	leak_pos = new int[leak_num];
	for (int i = 0; i < leak_num; i++) {
		cin >> leak_pos[i];
	}

	//ũ�� ������ ���� ������������ ����
	sort(leak_pos, leak_pos + leak_num);

	double last_pos = 0; // �������� �� ��ġ
	int count = 0; //�� ������ ��
	for (int i = 0; i < leak_num; i++) {
		if ((double)leak_pos[i] + 0.5 > last_pos) { //���� ���� �������� ������ �� �ٿ��ٸ�
			last_pos = max(leak_pos[i] - 0.5 + length, last_pos + length); // ���ο� ��ġ���� ���̰ų� �̾ ���̰ų�
			count++; //������ ��++
		}
	}

	//������
	cout << count;

	return 0;
}