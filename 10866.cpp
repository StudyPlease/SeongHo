#include <iostream>
#include <deque>
using namespace std;
//큐는 선입선출. 앞에서 삭제 뒤에서 삽입. 
//덱은 앞, 뒤 양 옆에서 삽입, 삭제 모두 가능.
//덱은 앞, 뒤에서 삽입, 삭제를 해야하고, 저장할 데이터 개수가 가변적이며 인덱스로 접근해야 할 때 쓰는 자료구조  
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