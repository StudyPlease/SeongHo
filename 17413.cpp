#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//���� ���� �ܾ�� ����ϰ�, �ܾ� ������. 
//<>�� ���� �κ��� ������ �ʱ�
//���ڿ� ���� ���� �����̽� �ϰ� <>�κ� ������ �������� ���ÿ� �ֱ�.
int main() {
	string input_str = "";
	stack<char> s;					//������ �� ����� ����
	vector<char> vec;				//������ ��� ���� ����

	getline(cin, input_str);		//���� ���� �Է�

	for (int i = 0; i < input_str.size(); i++) {
		if (input_str.at(i) == ' ') {		//�����̸� ���ÿ��� pop �ؼ� ���Ϳ� �ֱ�
			while (!s.empty()) {
				vec.push_back(s.top());		//���� top�� �ִ°� �ְ�
				s.pop();						//pop
			}
			vec.push_back(' ');
		}
		else if (input_str.at(i) == '<') {		//<������ �״�� > ���ö����� ���Ϳ� �ֱ� 
			while (!s.empty()) {
				vec.push_back(s.top());		//���� top�� �ִ°� �ְ�
				s.pop();						//pop
			}
			
			while (input_str.at(i) != '>') {	//>���ö����� �ֱ�. 
				vec.push_back(input_str.at(i));
				i++;
			}

			if (input_str.at(i) == '>') {		//���� �ڵ尡 ������ �ݵ�� >�� ����. 
				vec.push_back(input_str.at(i));
			}
		}	
		else {
			s.push(input_str.at(i));	//���ÿ� �ֱ� 
		}

		if (i == input_str.size() - 1) {	//������ �����̸�
			while (!s.empty()) {
				vec.push_back(s.top());		//���� top�� �ִ°� �ְ�
				s.pop();						//pop
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i);
	}

	return 0;
}