#include <iostream>
#include <vector>
#define max 1000000

using namespace std;
//4보다 큰 모든 짝수는 두 홀수이면서 소수인 수의 합으로 나타낼 수 있다. 
//N = a + b 로 출력. 여러개인 경우 b-a가 큰 것으로 출력
//소수를 구할 때는 에라토스테네스의 체 이용
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, a = 0, b = 0, check = 0;
	int prime_num[max + 1];		//1부터 백만까지 소수를 구할 배열.

	//초기화
	prime_num[1] = 0;
	for (int i = 2; i <= max; i++) {
		prime_num[i] = i;
	}

	//소수 찾기
	for (int i = 2; i * i <= max; i++) {
		if (prime_num[i] != 0) {						//이미 0이면 소수가 아닌 것으로 판정된 것이므로 다음 수로 이동
			for (int j = i * i; j <= max; j += i) {		//2i부터는 i의 배수이므로 모두 소수가 아님.
				prime_num[j] = 0;		//0으로 표시.
			}
		}
	}

	while (1) {
		cin >> N;		//짝수 입력
		if (N == 0) break;

		for (a = 3; a < N; a += 2) {		//a를 찾고 N에서 a를 빼면 b가 됨
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