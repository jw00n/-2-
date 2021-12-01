#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000; //1~100000

/*
data[0]~ data[n-1]�� ������ �ø��� ��ȣ�鿡 ���� �󵵼� ���̺��� ä��� �Լ�

param data
param n
table table[x] := data �迭���� x�� ������ Ƚ��
*/

//
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
	table.clear();//��� ���� ����
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //ũ�⸦ ���� �� 0���� �ʱ�ȭ , 100000 ǥ���� ���� +1

	for (int i = 0; i < n; ++i) { 
		int serial = data[i]; //������ ���� �ε�����
		table[serial] += 1; //table�� 1�� ����
	}
}

/*
data[0] ~ data[n-1]���� �ߺ��� �������� �ʴ� ���ҵ��� ��ȯ�Ѵ�.
��, �� ���ҵ��� ������������ ���ĵǾ� �־���Ѵ�.
data data[0] ~ data[n-1]���� 10�� ������ �ڿ�����.
n
return 
*/

vector<int> getUniqueElements(const vector<int>& data, int n) {

	vector<int> ret; //������ ���ҵ��� ���� �迭�� ����ִ� ���� ����, �迭�� �޸� ���� ����� �ƴ�

	
	vector<int> table;//table ����
	fillFrequencyTable(data, n, table); //data�� ���� �󵵼� ���̺��� ���

	//�ߺ��� �����ϱ� ���� for��
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) {
		//������ �� �ִ� ��� �ø��� �ѹ��� ���� ���ʷ� ��ȸ�Ѵ�.

		//��ü �����Ϳ��� �ѹ��� ������ number�� ���ʷ� ���� ����Ʈ ret�� �߰��Ѵ�.
		if (table[number] == 1) { //����Ƚ�� =1 ?
			ret.push_back(number); //������Ʈ
		}
	}

	//������������ �߰������Ƿ� ret ������ ���ʿ�
	return ret;
}

int main() {
	int n; //������ ��ȣ�� ���� ���� ���� 
	scanf("%d", &n);//�Է¹���

	vector<int> data = vector<int>(n); //���� �����̳ʷ� ũ�� n���� ����

	for (int i = 0; i < n; ++i) { //�迭�� ����������� ������ �Է¹���
		scanf("%d", &data[i]);

	}

	const vector<int> answer = getUniqueElements(data, n); //�ߺ��� ���ְ� ���� �ϳ��� ���ڸ��� �����ϴ� �Լ� ȣ��

	//�� ���ҵ��� ����Ѵ�.
	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0) { //i=0�϶��� �տ� ������ �ϳ� �߰��Ѵ�.
			printf(" ");
		}
		printf("%d", answer[i]); //���� ���
	}

	return 0;
}




/*
���� �����̳�: �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭
<vector> ��� ���� �߰�
using namespace std; ->ǥ�� ���ӽ����̽��� ����Ͽ� std::vector
vector�� ������ vector<data type> ������
vector<int> v -> ����ִ� �迭 ����
vector<int> v(5); -> 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� �迭 ����
vector<int> v(5,2); -> 5���� ���Ҹ� ���� �迭, ��� ���� 2�� �ʱ�ȭ
vector�� �������� ����Լ��� ����.

v.size(); -> ������ ���� ����
v.clear(); -> ��� ���� ����, ���Ҹ� �����ϰ� �޸𸮴� �״��
v.resize(n,3); -> ũ�⸦ n���� �����ϰ�, ������ ���� 3���� �ʱ�ȭ
v.push_back(7); -> ������ ���� �ڿ� ���� 7�� ����
�迭�� ����: ���� �߰�,����, ũ�⺯���� ��ƴ�
*/
