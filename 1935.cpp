#include <iostream>
#include <stack>
using namespace std;
//문자열에서 피연산자이면 스택에 push 
int main() {
	int operand_num = 0;
	double  first = 0, second = 0, result = 0;
	string formula = "";			//식
	int operand[26] = { 0, };		//A-Z까지 대응되는 수 저장
	stack<double> st;

	cin >> operand_num;
	cin >> formula;
	for (int i = 0; i < operand_num; i++) {
		cin >> operand[i];					//처음부터 나오는 알파벳부터 인덱스 0부터 시작
	}

	for (int i = 0; i < formula.size(); i++) {

		switch (formula[i]){
		case '+':
			second = st.top();
			st.pop();
			first = st.top();
			st.pop();
			st.push(first + second);
			break;
		case '-':
			second = st.top();
			st.pop();
			first = st.top();
			st.pop();
			st.push(first - second);
			break;
		case '*':
			second = st.top();
			st.pop();
			first = st.top();
			st.pop();
			st.push(first * second);
			break;
		case '/':
			second = st.top();
			st.pop();
			first = st.top();
			st.pop();
			st.push(first / second);
			break;
		default:		//숫자이면 push
			st.push((double)operand[formula[i] - 'A']);		//push하고 다음 인덱스로 이동
			break;
		}
	}
	result = st.top();
	cout << fixed;			//고정 소수점으로 출력
	cout.precision(2);		//소수점 두 자리 수 까지 
	cout << result;

	return 0;
}