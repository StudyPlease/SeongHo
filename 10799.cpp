#include <iostream>
#include <string>
#include <stack>
using namespace std;

//()�� �������� ǥ��. ( �� ) �� �踷����� �� ���� ǥ��. 
//�߷��� ������ �� ���� 
//������ ������ ���� ���ÿ� �ִ� �� ���ϰ� ��ƽ�� �� ������ +1
int main() {
	string input_str = "";	
	stack<char> s;			//push �� �ٷ� pop �Ͼ�� �������� ��.
	bool check = false;		//true�̸� ���� ��ȣ�� ������
	int sum = 0;			//�߷����� ���� �� ����
	cin >> input_str;
	
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str.at(i) == '(') {
			s.push('(');		//�ϴ� push 
			check = true;		//���� ��ȣ�� �������� ǥ��
		}
		else {
			if (check == true) {	//������ ���ʰ�ȣ�̸� ��������
				s.pop();			//������ ���ʰ�ȣ ����
				sum += s.size();	//��ƽ ��ȣ�� �� ����
			}
			else {					//������ �������̸� ��ƽ�� ����
				sum += 1;			//1 �����ְ�
				s.pop();			//��ƽ ���ʰ�ȣ ��
			}
			check = false;		//���� ��ȣ�� ���������� ǥ��
		}
	}
	cout << sum;

	return 0;
}