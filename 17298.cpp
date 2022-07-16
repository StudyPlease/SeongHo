#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//오큰수: 수열에서 해당 수의 오른쪽에 있으면서 큰 수 중에서 가장 오른쪽에 있는 수. 오큰수 없는 경우 -1

int NEG[1000000] = { 0, };		//전역변수는 데이터 영역에 저장되기 때문에 스택오버플로우가 발생하지 않음
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size = 0, num = 0, check = 0;
	vector<int> vec;
	stack<int> st;		//인덱스를 넣을 스택. 스택에 들어있는 인덱스는 아직 오큰수를 구하지 못한 인덱스임
	

	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;
		vec.push_back(num);		//수열 삽입 
	}

	for (int i = 0; i < size; i++) {
		//스택에 들어있는 값은 아직 오큰수를 구하지 못한 값의 인덱스
		while (!st.empty() && vec[st.top()]<vec[i]) {		//스택이 비어있지 않고 현재 top에 있는 인덱스에 해당하는 값에 오큰수가 있을 때 
			NEG[st.top()] = vec[i];		//오큰수를 해당되는 인덱스에 넣고 
			st.pop();					//오큰수를 구했으니 스택에서 pop
		}
		st.push(i);		//오큰수 구하지 못했으면 push
	}

	while (!st.empty()) {		//오큰수가 결국 없는 것들은 스택에 남아있음.
		NEG[st.top()] = -1;		//모두 -1 값을 넣어줌
		st.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << NEG[i] << " ";
	}

	return 0;
}