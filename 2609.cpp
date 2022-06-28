#include <iostream>
using namespace std;

//최소공약수는 유클리드 호제법으로 풀기. 큰 수를 작은 수로 모듈러 연산 하여 0인 나올 때 까지. 
//최소공배수*최대공약수 == 두 수의 곱
int main() {
	int num1 = 0, num2 = 0, return1 = 0, return2 = 0;
	int mid_num1 = 0, mid_num2 = 0, tmp = 0;
	cin >> num1 >> num2;

	if (num1 > num2) {		
		mid_num1 = num1;
		mid_num2 = num2;
		while (mid_num2) {
			tmp = mid_num2;
			mid_num2 = mid_num1 % mid_num2;
			mid_num1 = tmp;
		}
		return1 = mid_num1;		//최대공약수
	}
	else {
		mid_num1 = num2;
		mid_num2 = num1;
		while (mid_num2) {
			tmp = mid_num2;
			mid_num2 = mid_num1 % mid_num2;
			mid_num1 = tmp;
		}
		return1 = mid_num1;
	}
	return2 = num1 * num2 / return1;		//최소공배수

	cout << return1 << "\n" << return2 << "\n";

	return 0;
}