#include <iostream>
#include <stack>
using namespace std;
//���ڿ����� �ǿ������̸� ���ÿ� push 
int main() {
	int operand_num = 0;
	double  first = 0, second = 0, result = 0;
	string formula = "";			//��
	int operand[26] = { 0, };		//A-Z���� �����Ǵ� �� ����
	stack<double> st;

	cin >> operand_num;
	cin >> formula;
	for (int i = 0; i < operand_num; i++) {
		cin >> operand[i];					//ó������ ������ ���ĺ����� �ε��� 0���� ����
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
		default:		//�����̸� push
			st.push((double)operand[formula[i] - 'A']);		//push�ϰ� ���� �ε����� �̵�
			break;
		}
	}
	result = st.top();
	cout << fixed;			//���� �Ҽ������� ���
	cout.precision(2);		//�Ҽ��� �� �ڸ� �� ���� 
	cout << result;

	return 0;
}