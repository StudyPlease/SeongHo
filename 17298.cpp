#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//��ū��: �������� �ش� ���� �����ʿ� �����鼭 ū �� �߿��� ���� �����ʿ� �ִ� ��. ��ū�� ���� ��� -1

int NEG[1000000] = { 0, };		//���������� ������ ������ ����Ǳ� ������ ���ÿ����÷ο찡 �߻����� ����
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size = 0, num = 0, check = 0;
	vector<int> vec;
	stack<int> st;		//�ε����� ���� ����. ���ÿ� ����ִ� �ε����� ���� ��ū���� ������ ���� �ε�����
	

	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;
		vec.push_back(num);		//���� ���� 
	}

	for (int i = 0; i < size; i++) {
		//���ÿ� ����ִ� ���� ���� ��ū���� ������ ���� ���� �ε���
		while (!st.empty() && vec[st.top()]<vec[i]) {		//������ ������� �ʰ� ���� top�� �ִ� �ε����� �ش��ϴ� ���� ��ū���� ���� �� 
			NEG[st.top()] = vec[i];		//��ū���� �ش�Ǵ� �ε����� �ְ� 
			st.pop();					//��ū���� �������� ���ÿ��� pop
		}
		st.push(i);		//��ū�� ������ �������� push
	}

	while (!st.empty()) {		//��ū���� �ᱹ ���� �͵��� ���ÿ� ��������.
		NEG[st.top()] = -1;		//��� -1 ���� �־���
		st.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << NEG[i] << " ";
	}

	return 0;
}