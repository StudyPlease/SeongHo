#include <iostream>
#include <vector>
#define max 1000000

using namespace std;
//4���� ū ��� ¦���� �� Ȧ���̸鼭 �Ҽ��� ���� ������ ��Ÿ�� �� �ִ�. 
//N = a + b �� ���. �������� ��� b-a�� ū ������ ���
//�Ҽ��� ���� ���� �����佺�׳׽��� ü �̿�
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, a = 0, b = 0, check = 0;
	int prime_num[max + 1];		//1���� �鸸���� �Ҽ��� ���� �迭.

	//�ʱ�ȭ
	prime_num[1] = 0;
	for (int i = 2; i <= max; i++) {
		prime_num[i] = i;
	}

	//�Ҽ� ã��
	for (int i = 2; i * i <= max; i++) {
		if (prime_num[i] != 0) {						//�̹� 0�̸� �Ҽ��� �ƴ� ������ ������ ���̹Ƿ� ���� ���� �̵�
			for (int j = i * i; j <= max; j += i) {		//2i���ʹ� i�� ����̹Ƿ� ��� �Ҽ��� �ƴ�.
				prime_num[j] = 0;		//0���� ǥ��.
			}
		}
	}

	while (1) {
		cin >> N;		//¦�� �Է�
		if (N == 0) break;

		for (a = 3; a < N; a += 2) {		//a�� ã�� N���� a�� ���� b�� ��
			if (prime_num[a] != 0 && prime_num[N - a] != 0) {
				b = N - a;
				check = 1;
				break;
			}
		}

		if (check == 1) {
			cout << N << " = " << a << " + " << b << "\n";
		}
		else {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		
	}

	return 0;
}