#include <iostream>
#include <deque>
using namespace std;
//ť�� ���Լ���. �տ��� ���� �ڿ��� ����. 
//���� ��, �� �� ������ ����, ���� ��� ����.
//���� ��, �ڿ��� ����, ������ �ؾ��ϰ�, ������ ������ ������ �������̸� �ε����� �����ؾ� �� �� ���� �ڷᱸ��  
int main() {
	int num = 0, push_num = 0;
	string command = "";
	deque<int> dq;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> command;
		if (command == "push_front") {			
			cin >> push_num;
			dq.push_front(push_num);
		}
		else if (command == "push_back") {		
			cin >> push_num;
			dq.push_back(push_num);	
		}
		else if (command == "pop_front") {
			if (dq.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front();
				dq.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (dq.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back();
				dq.pop_back();
			}
		}
		else if (command == "size") {
			cout << dq.size();
		}
		else if (command == "empty") {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (command == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (command == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
	}


	return 0;
}