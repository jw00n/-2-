#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	int N; //��ǥ ���� �� N
	cin >> N; //�Է¹޴´�.

	//�� �ĺ� �̸��� ��ǥ ���� �����ϴ� key-value Map���� ����
	map<string, int> frequencyMap;

	int maxFrequency = 0; //���� ���� ��ǥ�� �����ϴ� ����//ó������ 0���� �ʱ�ȭ

	//�� �̸��� �ϳ� �߰��ɶ����� ��������� �˴� ��ǥ �� ����, �ִ� ��ǥ �ĺ� ����Ʈ�� �����Ѵ�.

	for (int i = 0; i < N; i++){
		string st; //�ĺ����� �̸� st //�ĺ����� �̸��� ���ĺ� �빮�� ���ڿ��̴�.
		cin >> st; //�Է¹޴´�.
		frequencyMap[st]++; //�Է¹��������� �ش� key(�ĺ���)�� value���� ++ //0���� 1�� ����
		int k = frequencyMap[st]; //value(��ǥ ��)�� k�� �ӽ�����
		if (k > maxFrequency) { //�ִ� ��ǥ���� ���Ͽ�
			maxFrequency = k; //k�� ũ�ٸ� k�ǰ����� maxFrequency�� ������Ʈ
		}
	}


	//�ִ� ��ǥ ���� ����Ѵ�.
	cout << maxFrequency << endl;

	//�ִ� ��ǥ�� �����ĺ��� �̸��� ���������� ����Ѵ�.
	map<string, int>::iterator it;

	//�� �ĺ��� �̸��� ��ǥ���� ����� frequencyMap���� begin ~ end ���� �ִٵ�ǥ���� ���� �ĺ��̸�(key) ���
	//���� ������ ��µ�.
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
		if (it->second == maxFrequency) //value���� �ִٵ�ǥ���� �����Ҷ�
			printf("%s ",it->first.c_str()); //first�� string���̹Ƿ� c_str()�� �ٿ� �����Ѵ�.
	}

}