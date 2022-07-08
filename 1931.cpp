#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//������ �ð��� ���� �� ������� ����

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
	if (meet1.end == meet2.end) {			//������ �ð� ������ ���� �ð� ���� �������� ����
		return meet1.start < meet2.start;
	}
	else {						
		return meet1.end < meet2.end;		//end�� �������� �������� ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);		//stdio ���� ����ȭ ����
	int meeting = 0, end = 0;				//ȸ�� ��, �����½ð�
	cin >> meeting;
	vector<Meet> meet;						//ȸ�� ������ ����
	for (int i = 0; i < meeting; i++) {
		//�ٵ� �̰� �� protedted�� �ϸ� ���� �ȵǴ���??
		int start = 0, end = 0;
		cin >> start >> end;				//ȸ���� ���۽ð�, ������ �ð� �Է�
		Meet m(start, end);					//ȸ�� ��ü ����
		meet.push_back(m);					//���Ϳ� �߰�
	}
	sort(meet.begin(), meet.end(), cmp);		//Meet ��ü���� ������ �ð��� ���� ������� ���� 

	int cnt = 1, idx = 1;
	end = meet[0].end;					//������ ȸ���� ������ �ð�.
	while (idx < meeting) {
		if (end <= meet[idx].start) {	//������ ȸ���� ������ �ð��� ���� ��ȸ���� �ε����� �����ϴ� �ð����� �۰ų� ������ ���� ȸ�� ����
			end = meet[idx].end;
			cnt++;
		}
		idx++;
	}
	cout << cnt;		//���� ������ ȸ�� �� ���

	return 0;
}