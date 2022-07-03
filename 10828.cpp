#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t_case = 0, num = 0;	
	string command;				//��ɾ�
	stack<int> s;

	cin >> t_case;
	for (int i = 0; i < t_case; i++) {
		cin >> command;
		if (command == "push") {		//������ �� ���� ���� ����
			cin >> num;
			s.push(num);
		}
		else if (command == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (command == "size") {
			cout << s.size() << "\n";
		}
		else if (command == "empty") {
			if (s.empty()) {
				cout << 1 << "\n";		//��������� 1 ���
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (command == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}

	return 0;
}