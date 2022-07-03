#include <iostream>
#include <algorithm>		//min

//제곱수의 합으로 나타낼 때 최소 항의 개수
//dp로 풀기. 
using namespace std;
int main() {
	int dp[100001] = { 0, };
	int input = 0;
	cin >> input;

	for (int i = 0; i <= input; i++) {
		dp[i] = i;		//모든 dp배열을 1의 제곱의 합이라 생각하고 초기화. ex) 5 = 1+1+1+1+1=5이므로 항의 수는 5. 이를 이제 최소값으로 초기화 시켜줄 것임. 
	}

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);		//결국 이전 값보다 1이 크기 때문에 1을 더해줌. 
		}
	}

	cout << dp[input];

	return 0;
}
