#include <algorithm>
#include <iostream>
#include<vector>
#include<time.h>

using namespace std;


int getWhichfood(int k, const vector<int>& foodTime) {
	int sum = 0; //������ �Դ� �� �ҿ� �ð� ���庯��
	int time = 0; 
	int pretime = 0; //������ ���� ���� �ð�
	int size = foodTime.size(); // =���� ����

	vector<pair<int, int>> range; //���ĸԴ� �ð�, �ε��� �����ϴ� ����

	for (int i = 0; i < foodTime.size(); i++) {
		sum += foodTime[i];	//��� ���� �ҿ�ð��� ���� sum
		range.push_back(make_pair(foodTime[i], i + 1)); //���� �ð��� �ε����� ���� �ϳ��� ��ü���
	}
	sort(range.begin(), range.end()); //�������� ����

	if (sum <= k) return -1; //����ߴܽð��� ��� ���ļ���ð��� ��ġ�ϸ� �� ��������̹Ƿ� -1 ��ȯ


	for (vector<pair<int, int>>::iterator i = range.begin(); i != range.end(); i++) {
		time = (i->first - pretime) * size; //������������ ���������� ù��° ���ҿ��� �����ð��� �� �� * ���İ��� ->���� �ð��� ���� �ɸ��� ������ �ҿ��ϴ� �ð�
		
		if (time <= k) {//���� time�� k(�ߴܽð�)���� ���ų� �۴ٸ�
			k -= time; //k���� ���ҽ�Ų��.
			pretime = i->first; //pretime�� ���� ���� �ð��̹Ƿ� ������Ʈ
		}
		else {//k�� time���� �۾������� �� ���� �� ����Ŭ�� ���� ���ϰ� �ߵ����� ���⶧
			sort(i, range.end());  //������������ ����
			return (i + (k % size))->second; // �ε����� ã�� �������ش�.
		}
		size--; //���İ����� ���ҽ��Ѽ� �ݺ�
	}


}



void process(int n) {

	vector<int> foodTime;//���� �ð��� �����ϴ� ����

	//�� ������ �Դ� �ð��� �Է¹޾� ���Ϳ� �����Ѵ�.
	for (int i = 0; i < n; i++) {
		int eachTime;
		cin >> eachTime;
		foodTime.push_back(eachTime);
	}

	int k; //�ߴܵ� �ð��� �Է�
	cin >> k; //�Է¹޴´�.
	clock_t start, end; //�ð� ����
	start = clock();//��������

	int answer = getWhichfood(k, foodTime); //�μ��� ���ĸԴ� �ð��� ������ ���Ϳ� �O�� �ð� k�� �Ѱ��ش�.

	cout << answer << endl; // �� �� ���ĺ��� �Ծ�� ���� ��� 
	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���

}

int main() {

	int n; //������ ���� n�� �Է¹޴´�.
	cin >> n;

	//���μ��� ����
	process(n);
 
	return 0;
}