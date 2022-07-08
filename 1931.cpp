#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//끝나는 시간이 빠른 것 순서대로 배정

class Meet {
public:
	int start;
	int end;
	Meet() {
		start = 0;
		end = 0;
	}
	Meet(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
bool cmp(Meet& meet1, Meet& meet2) {
	if (meet1.end == meet2.end) {			//끝나는 시간 같으면 시작 시간 기준 오름차순 정렬
		return meet1.start < meet2.start;
	}
	else {						
		return meet1.end < meet2.end;		//end를 기준으로 오름차순 정렬
	}
}

int main() {
	ios_base::sync_with_stdio(false);		//stdio 버퍼 동기화 해제
	int meeting = 0, end = 0;				//회의 수, 끝나는시간
	cin >> meeting;
	vector<Meet> meet;						//회의 저장할 벡터
	for (int i = 0; i < meeting; i++) {
		//근데 이거 왜 protedted로 하면 접근 안되는지??
		int start = 0, end = 0;
		cin >> start >> end;				//회의의 시작시간, 끝나는 시간 입력
		Meet m(start, end);					//회의 객체 생성
		meet.push_back(m);					//벡터에 추가
	}
	sort(meet.begin(), meet.end(), cmp);		//Meet 객체들의 끝나는 시간이 빠른 순서대로 정렬 

	int cnt = 1, idx = 1;
	end = meet[0].end;					//배정된 회의의 끝나는 시간.
	while (idx < meeting) {
		if (end <= meet[idx].start) {	//배정된 회의의 끝나는 시간이 현재 순회중인 인덱스의 시작하는 시간보다 작거나 같으면 현재 회의 배정
			end = meet[idx].end;
			cnt++;
		}
		idx++;
	}
	cout << cnt;		//최종 배정된 회의 수 출력

	return 0;
}