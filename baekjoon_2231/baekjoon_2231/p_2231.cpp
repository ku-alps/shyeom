#include <iostream>
using namespace std;

int main() {
	int N;
	int M = 1; 
	cin >> N;
	while (M <= N) {
		int temp = M, sum = M;
		for (int i = 1000000; i > 0; i/=10) {
			sum += temp / i;
			temp = temp % i; 
		}
		if (sum == N)
			break;
		else
			M++;
	}

	if (M > N ? cout << 0 : cout << M);

	return 0;
}
