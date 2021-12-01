#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class City {

public:
	int index; //������ �ε���
	int income; //�ش� ������ �ҵ�

	//���ڷ� �޾Ƽ� �� ����
	City(int index, int income) {
		this->index = index;
		this->income = income;
	}

	//income�� �̿��� ��� ���� 
	bool operator < (const City& o) const {
		return this->income < o.income;
	}

	bool operator > (const City& o) const {
		return this->income > o.income;
	}
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	int answer = 0; //���� ū �ҵ����� ����� ���� //0���� �ʱ�ȭ 

	//�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱 ���� ť

	//priority_queue<Ŭ����, ���� �����̳�, ���Լ� Ŭ����>
	//Ŭ������ �񱳿����� �� ��� Ŭ������ ���ǵǾ��־���Ѵ�.
	//ž���� ���� ���������̹Ƿ� ž�� ���� ���� -> ž ���� = �ּҰ� ����
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	//�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱���� ť
	priority_queue<City> rangeMaximum;
	//������ Ÿ�Ը� ���� ��� less�� ������ ����̴�.
	//priority_queue<City, vector<City>, less<City>> rangeMaximum;

	//�̷��� �ϸ� O(n) �ð����⵵�� �ڵ�����

	//ex) income 10 2 5 3 7 9 1
	for (int i = 0; i < k - 1; i++) { //k=3 -> k-1 =2 
		rangeMaximum.push(cities[i]); // ū ���� ���� ���� ���ĵ�.
		rangeMinimum.push(cities[i]); // ���� ���� ���� ����.
	}

	//i=2���� ~n���� �ݺ�
	for (int i = k - 1; i < n; i++) {
		//cities ������ �ְԵ�
		rangeMaximum.push(cities[i]); //top = ���� ū ������ ������� ���ĵ�
		rangeMinimum.push(cities[i]); //top = ���� ���� �� ���� ���ĵ�
		//while������ top���� ������. -> ��� �������� �ִ��ּҰ��� ���ϴ°� �ƴ� ������ ���� k�� �����ȿ��� ���ؾ��ϱ� ����
		//��ġ���� -> index�� �����ȿ� �־����. ���� ���̸� pop�� ����
		while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop(); 
		while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();
		//�� ���� �ݺ����� ���� ���� ���� ��� ���ϸ� answer�� ������Ʈ
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
	}

	//�������� answer = ���� ū �ҵ� ������ ����
	return answer;



}

//caseindex�� ���� ������� �ʾƼ� ���ڷ� �� �ʿ�� �����.
void process(int caseIndex) {
	int n, k; //n = ������ �� //k= �� ���� ������ �����ϴ� ������ ������ ��
	cin >> n >> k;//�Է�
	vector<City> cities; //���� ���� ���� //������ Ÿ���� City Ŭ������ ����

	for (int i = 0; i < n; i += 1) {
		int income;//�ҵ�����
		cin >> income;//�Է¹޾Ƽ�
		cities.push_back(City(i, income)); //�ε����� �ҵ� ������ cityŬ������ ���Ϳ� ����
	}

	//�ҵ� ������ ����ϴ� �Լ��� ���� ���� ū �ҵ����� �˾Ƴ��� answer�� ����
	int answer = getMaximumRangeDifference(n, k, cities);

	//���
	cout << answer << endl;
}


int main() {
	int caseSize; //�׽�Ʈ  ���̽� ���� �Է¹޴´�.
	cin >> caseSize;

	//���̽� ���ڸ�ŭ �ݺ��ϸ� ���μ��� ����
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}


}

//���� for������ �����ϰ� �Ǹ� �ð����⵵�� O(n^2)���� ��ȿ������ ���̴�.
//�켱���� ť�� ���� ȿ������ ���� �߱��ϴ� ���� ��ǥ��+