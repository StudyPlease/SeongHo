#include <iostream>
#include <algorithm>		//min

//�������� ������ ��Ÿ�� �� �ּ� ���� ����
//dp�� Ǯ��. 
using namespace std;
int main() {
	int dp[100001] = { 0, };
	int input = 0;
	cin >> input;

	for (int i = 0; i <= input; i++) {
		dp[i] = i;		//��� dp�迭�� 1�� ������ ���̶� �����ϰ� �ʱ�ȭ. ex) 5 = 1+1+1+1+1=5�̹Ƿ� ���� ���� 5. �̸� ���� �ּҰ����� �ʱ�ȭ ������ ����. 
	}

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);		//�ᱹ ���� ������ 1�� ũ�� ������ 1�� ������. 
		}
	}

	cout << dp[input];

	return 0;
}
