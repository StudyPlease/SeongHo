#include <iostream>
#include <string>
#include <list>
//L: 왼쪽으로 한 칸 D: 오른쪽으로 한 칸(맨 뒤면 무시) 
//B: 왼쪽에 있는 문자 삭제(맨 앞이면 무시) P $ : $를 왼쪽에 추가. 
//그니까 그냥 키보드 동작 생각하면 됨. 
//처음 문자열 주어지고, 모든 명령 수행 후 남은 문자열 출력. 
//맨 처음에는 커서 문장 맨 뒤
//맨 앞: 커서(문자)(문자)(문자)    맨 뒤: (문자)(문자)(문자)커서
//STL list에서 end()는 마지막 원소의 다음 원소를 가리킨다. 따라서, 현재 지우려는 문자의 다음 문자를 커서라고 생각하고 문제를 풀었다.
using namespace std;

int main() {
	string input_str = "";	//입력 문자열
	int command_num = 0;		//입력할 명령어 갯수
	char command = 0, word = 0;			//입력할 명령어
	list<char> linked_list;		//문자열을 문자로 쪼개어 저장할 연결리스트
	list<char>::iterator iter = linked_list.end();		//연결리스트 마지막을 가리키는 이터리이터

	cin >> input_str;
	for (int i = 0; i < input_str.size(); i++) {
		linked_list.push_back(input_str.at(i));		//한글자씩 삽입
	}
	iter = linked_list.end();		//이터레이터는 현재 문자의 다음 문자에 위치해 있다고 생각.

	cin >> command_num;
	while (command_num--) {		//명령 수만큼 반복
		cin >> command;
		switch (command) {
		case 'L':
			if (iter == linked_list.begin()) {		//만약 이미 맨 앞이면
				break;		//무시
			}
			iter--;
			break;
		case 'D':
			if (iter == linked_list.end()) {		//만약 이미 맨 뒤이면
				break;		//무시
			}
			iter++;
			break;
		case 'B':
			if (iter == linked_list.begin()) {		//만약 이미 맨 앞이면
				break;		//무시
			}
			iter = linked_list.erase(--iter);		//앞 원소로 이동해 값 삭제
			break;
		case 'P':
			cin >> word;
			linked_list.insert(iter, word);		//이터레이터 위치에 삽입. 편집기에서 커서 앞에 삽입하는 것과 같은 동작. 
			break;
		}
	}
	for (iter = linked_list.begin(); iter != linked_list.end(); iter++) {
		cout << *iter;
	}

	return 0;
}