#include <iostream>
#include <string>
#include <list>
//L: �������� �� ĭ D: ���������� �� ĭ(�� �ڸ� ����) 
//B: ���ʿ� �ִ� ���� ����(�� ���̸� ����) P $ : $�� ���ʿ� �߰�. 
//�״ϱ� �׳� Ű���� ���� �����ϸ� ��. 
//ó�� ���ڿ� �־�����, ��� ��� ���� �� ���� ���ڿ� ���. 
//�� ó������ Ŀ�� ���� �� ��
//�� ��: Ŀ��(����)(����)(����)    �� ��: (����)(����)(����)Ŀ��
//STL list���� end()�� ������ ������ ���� ���Ҹ� ����Ų��. ����, ���� ������� ������ ���� ���ڸ� Ŀ����� �����ϰ� ������ Ǯ����.
using namespace std;

int main() {
	string input_str = "";	//�Է� ���ڿ�
	int command_num = 0;		//�Է��� ��ɾ� ����
	char command = 0, word = 0;			//�Է��� ��ɾ�
	list<char> linked_list;		//���ڿ��� ���ڷ� �ɰ��� ������ ���Ḯ��Ʈ
	list<char>::iterator iter = linked_list.end();		//���Ḯ��Ʈ �������� ����Ű�� ���͸�����

	cin >> input_str;
	for (int i = 0; i < input_str.size(); i++) {
		linked_list.push_back(input_str.at(i));		//�ѱ��ھ� ����
	}
	iter = linked_list.end();		//���ͷ����ʹ� ���� ������ ���� ���ڿ� ��ġ�� �ִٰ� ����.

	cin >> command_num;
	while (command_num--) {		//��� ����ŭ �ݺ�
		cin >> command;
		switch (command) {
		case 'L':
			if (iter == linked_list.begin()) {		//���� �̹� �� ���̸�
				break;		//����
			}
			iter--;
			break;
		case 'D':
			if (iter == linked_list.end()) {		//���� �̹� �� ���̸�
				break;		//����
			}
			iter++;
			break;
		case 'B':
			if (iter == linked_list.begin()) {		//���� �̹� �� ���̸�
				break;		//����
			}
			iter = linked_list.erase(--iter);		//�� ���ҷ� �̵��� �� ����
			break;
		case 'P':
			cin >> word;
			linked_list.insert(iter, word);		//���ͷ����� ��ġ�� ����. �����⿡�� Ŀ�� �տ� �����ϴ� �Ͱ� ���� ����. 
			break;
		}
	}
	for (iter = linked_list.begin(); iter != linked_list.end(); iter++) {
		cout << *iter;
	}

	return 0;
}