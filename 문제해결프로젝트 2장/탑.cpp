#include<iostream>
#include<stack>
#include<vector>

using namespace std;



class Tower {
public:
	int index; //Ÿ���� �ε���(��ġ����)
	int height; //Ÿ���� ����
	int targetTowerIndex; //�� Ÿ���� �������� �����ϴ� ��� Ÿ��

	Tower(int index, int height){
		this->index = index; //���� ���ڷ� �����ϰ�
		this->height = height;
		this->targetTowerIndex = 0; //targetTower index��  0���� �ʱ�ȭ
	}


	//setTarget~ �� getTarget~���� targetTowerIndex���� �����ϰų� ��ȯ�Ѵ�.
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex() {
		return this->targetTowerIndex;
	}
};

/*
���ô�� ����������,

1. ó���� t.setTargetTowerIndex(targetTowerIndex); ���� �����. -> 0���� �����ϰ� �ȴ�.
> ���� stk.push(t)�� ���� 6�� ���ԵǰԵ�. ����� 0

2. 9�� ������ empty ==false �� �ǰ� 6�� 9�� ���ϰ� ��. 6�� �����Ƿ� ����
>  0 ���, push�� ���� 9�� �������� ����

3. ���� 5, 9�� ���ϰ� ���ǿ� �������� �����Ƿ� 9�� ��������. �ε����� 2�� ��� / 5 ���ÿ� ����

4. ���� 7 , 5�ϰ� �� -> 5�� �� �����Ƿ� ���� -> 7�� 9�񱳿��� 9�� ������ �����ְ� ��ġ���� 2�� �ٽ� ��� /7 ���ÿ� ����

5. ���� 4, 4�� 7�񱳿��� 7�� ���Եǰ� 7�� �ε��� 4�� ���
*/

void findTargetTowers(vector<Tower>& towers) {
	//���� �ٸ� Ÿ���� ��ȣ�� ������ ���ɼ��� �ִ� Ÿ��
	stack<Tower> stk; //���ú��� ����

	//�ð����⵵ O(N)
	for (int i = 0; i < towers.size(); i++) {
		Tower& t = towers[i]; //�� Ÿ�� t�� ���� ���ʷ� ���
		int targetTowerIndex = 0; //Ÿ�� t�� ��ȣ�� ������ �ĺ� (�ʱⰪ null)

		while (stk.empty() == false 
			&& stk.top().height < t.height) {
			//t���� ���̰� ���� Ÿ������ ���Ŀ��� ���� ���ɼ��� �����Ƿ� ����
			stk.pop();
		}

		//t�̻��� ���̸� ���� Ÿ���� �����ִٸ�?
		if (stk.size() > 0) {
			//t�� �ش� Ÿ���� Ÿ������ ���ϰ� �ȴ�.
			targetTowerIndex = stk.top().index;
		}
		//����� Ÿ�� ������ �����Ѵ�.
		t.setTargetTowerIndex(targetTowerIndex);

		//t�� �������� ���������Ƿ� �ٸ� Ÿ���� ��ȣ�� ������ �� �ִ�. ���
		stk.push(t); 
	}
}

int main() {
	int n; //ž�� ���� N
	cin >> n; //n�� �Է¹޴´�.


	vector<Tower> towers; //���� ���� ����
	for (int i = 0; i < n; ++i) { //ž�� ������ŭ �ݺ��ϸ� ž���� ���̸� �Է¹޴´�.
		int hi;
		cin >> hi; //ž ���� h1
		towers.push_back(Tower(i + 1, hi)); //���� ������ �ε��� 1���� ����
	}

	//�� Ÿ���� �۽��ϴ� �������� ���� Ÿ���� ��� ����Ѵ�.
	findTargetTowers(towers);

	//����ϴ� �ݺ���
	for (int i = 0; i < n; i++) {
		if (i > 0) { //i=1���� ���� ���
			cout << " ";
		}

		Tower t = towers[i]; 
		int targetIndex = t.getTargetTowerIndex(); //������� �ε��� ��ȯ�Ǿ�
		cout << targetIndex; //���
	}
}

//������ ���Ի����� ���κп����� �Ͼ�ٸ� ������ ���<<

/* ���þ��� �ϴ� �� / �ð����⵵ O(N^2)
for(i=0~N-1)
{
	int target =0;
	for(j=i-1~0)
	{
		if(h[j]>h[i])
		{
			target =j;
			break;
		}
	}
}

*/