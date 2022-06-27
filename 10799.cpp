#include <iostream>
#include <string>
#include <stack>
using namespace std;

//()는 레이저를 표현. ( 와 ) 는 쇠막대기의 양 끝을 표현. 
//잘려진 조각의 총 갯수 
//레이저 만나면 현재 스택에 있는 수 더하고 스틱의 끝 만나면 +1
int main() {
	string input_str = "";	
	stack<char> s;			//push 후 바로 pop 일어나면 레이저인 것.
	bool check = false;		//true이면 이전 괄호가 왼쪽임
	int sum = 0;			//잘려지는 지점 총 갯수
	cin >> input_str;
	
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str.at(i) == '(') {
			s.push('(');		//일단 push 
			check = true;		//이전 괄호가 왼쪽임을 표시
		}
		else {
			if (check == true) {	//이전이 왼쪽괄호이면 레이저임
				s.pop();			//레이저 왼쪽괄호 빼고
				sum += s.size();	//스틱 괄호들 수 더함
			}
			else {					//이전이 오른쪽이면 스틱의 끝임
				sum += 1;			//1 더해주고
				s.pop();			//스틱 왼쪽괄호 뺌
			}
			check = false;		//이전 괄호가 오른쪽임을 표시
		}
	}
	cout << sum;

	return 0;
}