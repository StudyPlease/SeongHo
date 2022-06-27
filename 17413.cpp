#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//공백 기준 단어로 취급하고, 단어 뒤집기. 
//<>로 묶인 부분은 뒤집지 않기
//문자열 공백 기준 슬라이싱 하고 <>부분 제외한 나머지는 스택에 넣기.
int main() {
	string input_str = "";
	stack<char> s;					//뒤집을 때 사용할 스택
	vector<char> vec;				//뒤집은 결과 넣을 벡터

	getline(cin, input_str);		//공백 포함 입력

	for (int i = 0; i < input_str.size(); i++) {
		if (input_str.at(i) == ' ') {		//공백이면 스택에서 pop 해서 벡터에 넣기
			while (!s.empty()) {
				vec.push_back(s.top());		//스택 top에 있는거 넣고
				s.pop();						//pop
			}
			vec.push_back(' ');
		}
		else if (input_str.at(i) == '<') {		//<나오면 그대로 > 나올때까지 벡터에 넣기 
			while (!s.empty()) {
				vec.push_back(s.top());		//스택 top에 있는거 넣고
				s.pop();						//pop
			}
			
			while (input_str.at(i) != '>') {	//>나올때까지 넣기. 
				vec.push_back(input_str.at(i));
				i++;
			}

			if (input_str.at(i) == '>') {		//위의 코드가 끝나면 반드시 >가 나옴. 
				vec.push_back(input_str.at(i));
			}
		}	
		else {
			s.push(input_str.at(i));	//스택에 넣기 
		}

		if (i == input_str.size() - 1) {	//마지막 문자이면
			while (!s.empty()) {
				vec.push_back(s.top());		//스택 top에 있는거 넣고
				s.pop();						//pop
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i);
	}

	return 0;
}