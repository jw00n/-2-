#include <stdio.h>
#include <vector> //push_back, size
#include<algorithm> //sort, binary_search

using namespace std;

/*
�ߺ��� ������ �� ī���� ������ ���� �� �ִ� ��÷��ȣ�� ���� ����ϴ� �Լ�
param
n - ī���Ǽ�
m - �˻��Ϸ��� ��÷��ȣ�� ��
cards - �� ī�忡 ���� �����ڵ�
target - �˻��Ϸ��� �� ��÷��ȣ ����Ʈ
@return

*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets)
{
	vector<int> possibleTargets; //���� �� �ִ� ��÷��ȣ��

	//���̳ʸ� ��ġ�� ���� ���� -> ��� ī�带 ������������ "����"�Ѵ�. 
	sort(cards, cards + n); //sort(������ġ, �� ��ġ) //cards, cards+n���� n���� ��� ���Ҹ� ���Ľ�Ŵ

	for (int i = 0; i < m; ++i) // m= ��÷��ȣ�� ����ŭ �ݺ�
	{
		int k = targets[i];//��� Ÿ�� k�� ���Ͽ�
		bool possible = false; //ó���� false��

		for (int j = 0; j < n; ++j){ //���� 3���� ���� ���� �ݺ���
			int x = cards[j]; //��� ī�� �� �ϳ��� x�� ���Ͽ�

			for (int p = 0; p <= j; p += 1)//���� ������ �ߺ� ���ֱ� ���귮�� ���̱� ���� j���� �ݺ�
			{
				int y = cards[p];//ī�� �� �ϳ� y�� �����Ѵ�.
				int z = k - (x + y); //k=(x+y) +z �� �Ǵ� z�� ����Ѵ�.

				//z�� cards[]�� �����Ѵٸ�?
				if (binary_search(cards, cards + n, z) == true) //binary_search(������ġ, ����ġ, ã�� ��)���� z�� ã�´�.
				{
					possible = true;	//k = x+y+z �� ������ <x, y, z>�� �����Ѵ�. -> true
					break; //->3��° for������ ���
				}
			}

			if (possible) { //�̹� ã�Ҵٸ� Ż���Ѵ�.
				break; //->�� ��° for������ Ż��
			}
		}

		if (possible) { //�� ī���� ������ k�� ���� �� �ִٸ�, �߰��Ѵ�.
			possibleTargets.push_back(k); 
		}
	}

	sort(possibleTargets.begin(), possibleTargets.end()); //k�� �߰��� ���ĹǷ� ������������ ����
	return possibleTargets; //��°��� ����Ǿ��ִ� ���� ����
}


int main() {
	int n; // ī���� ��
	int m; // �˻� �� �ĺ� ��÷��ȣ�� ��

	scanf("%d %d", &n, &m);// �����͸� �Է¹���

	int *cards = new int[n]; //n�� ��ŭ ũ���� ī���ȣ �迭
	int *targets = new int[m];//m�� ��ŭ ũ���� ��÷��ȣ �迭

	//�� ī�� ������ �Է¹޴´�.
	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}

	//�� �ĺ� ��÷��ȣ�� �Է¹޴´�.
	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}

	//getPossibleTargets�� ���� �� ���� ������ ������ ǥ���� �� �ִ� ��÷��ȣ�� ���Ѵ�.
	vector<int>  answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0) //������ ��÷��ȣ�� ����?
	{
		printf("NO"); //NO ���
	}

	else //������ ��÷��ȣ�� �����Ѵٸ� �� ����� ����Ѵ�.
	{
		for (int i = 0; i < answers.size(); i++)
		{
			if (i > 0)// ���� ���� ���
			{
				printf(" ");
			}
			printf("%d", answers[i]); //���ǿ� ������ ���ĵ� ���� ��µȴ�.
		}
	}

	//�����ٸ� ����ݴϴ�.
	delete[] cards;
	delete[] targets;

	return 0;
}