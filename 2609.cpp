#include <iostream>
using namespace std;

//�ּҰ������ ��Ŭ���� ȣ�������� Ǯ��. ū ���� ���� ���� ��ⷯ ���� �Ͽ� 0�� ���� �� ����. 
//�ּҰ����*�ִ����� == �� ���� ��
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
		return1 = mid_num1;		//�ִ�����
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
	return2 = num1 * num2 / return1;		//�ּҰ����

	cout << return1 << "\n" << return2 << "\n";

	return 0;
}