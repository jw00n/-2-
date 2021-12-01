#include<iostream>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;

class Histogram {
public:
	int height; //������׷��� ����
	int leftX; //�ε��� Ȥ�� ������׷��� ���� ���� x ��ǥ
	int rightX; //������׷��� ������ ���� x��ǥ

	Histogram(){ }

	Histogram(int index, int height) {
		this->leftX = index; //�ε����� x��ǥ
		this->rightX = this->leftX + 1; //�� ������׷��� �ʺ� 1�̹Ƿ� +1
		this->height = height; //����
	}

};

long long getLargeRectangleArea(const vector<Histogram>& histograms) {
	long long answer = 0; //�ִ� ���簢���� ����

	//���� �������� Ȯ�� ���ɼ��� ���� ������׷�
	stack<Histogram> stk; //���� ����

	//������ ���Ǹ� ���� ���� ���ʿ� ���� 0���� ������ ������׷� �߰�
	stk.push(Histogram(-1, 0));

	for (int i = 0; i < histograms.size() + 1; i++) {
		//���ʺ��� ������ ����Ʈ�׷����� ���ʷ�
		Histogram h;
		if (i < histograms.size()) { //i�� size������ �۴ٸ�
			h = histograms[i]; //h�� �ε��� i�� ������׷� �־��ش�.
			
		}
		else {
			//if(i==n)
			//������ ���Ǹ� ���� ����  �����ʿ� ���� 0���� ������ ������׷� �߰�
			h = Histogram(histograms.size(), 0);
		}

		//������ Ȯ�� ���̴� ������׷��� ��, h ���� ���̰� ���� ������׷�����
		//���̻� Ȯ��� �� ���� -> �ִ� ���� �����ȴ�.
		while (stk.size() > 1
			&& stk.top().height > h.height) { //size�� 1���� ũ�� ���� ������׷��� �� ������ �ݺ���.
			//Ȯ�����̴� ������׷�//���̰� ������������ //�ƴ϶�� Ȯ���� �Ұ����ϹǷ� �����Ŵ
			Histogram lh = stk.top(); //�����ϱ� ���� top�� ���߿� ����ϱ� ����
			stk.pop(); //���� ����

			//�� ������ ������׷� (���� Ȯ���� ��)
			Histogram bh = stk.top(); //�ʱⰪ�� 0 , ���� �� ���� ������׷��� ����
			

			//���� �߰��� h�� �ٷ� ���ʱ��� Ȯ����
			long long width = abs(h.leftX - bh.rightX); //���� �̿��� �ʺ� ����
			long long height = lh.height; //����
			long long area = width * height; //����

			//��� ���ϸ� �ִ밪 ����
			answer = max(answer, area);
		}

		//h�� ������ �߰��Ѵ�.
		stk.push(h);
	}
	return answer;//��� ����
}

void process(int caseIndex) {
	int n; //�׷��� ����
	cin >> n;//�Է�

	vector<Histogram> histograms; //���� ���� ����
	for (int i = 0; i < n; i++) {
		int height; 
		cin >> height; //�ݺ����� ���� height���� �Է¹޾�
		histograms.push_back(Histogram(i, height)); //�ε����� height�� ����
	}

	//answer�� 10���� �������� �ִ�� �� �� �����Ƿ� long long Ÿ��
	long long answer = getLargeRectangleArea(histograms); //histograms�� �ִ� ���̸� ����Ͽ� answer�� �־��ش�.
	cout << answer << endl; //answer ���

}

int main() {
	int caseSize; //�׽�Ʈ ���̽� ��
	cin >> caseSize; //���̽� ������ �Է¹޴´�. 

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex); //���̽� ������ŭ process ȣ��
	}
}


/* 3�� �ݺ��� - �ð����⵵ O(n^3)
for(int l = 0 ~ n-1)
{
	for(int r=l ~ n-1)
	{
		for(int i= l~r)
		{
		//���� �ּҰ� ���ϱ�
		//���� = (r-l+1)*���� �ּҰ�
		}
	}
}

*/