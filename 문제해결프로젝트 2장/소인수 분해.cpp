#include<cstdio>
#include<vector>

using namespace std;

/*
�ڿ��� N�� �����ϴ� ��� ���μ��� ��ȯ�ϴ� �Լ�

param N
return
*/

vector<int> factorize(int n) {
	vector<int> factors; //���ͺ��� ����

	for (int div = 2; div * div <= n; div += 1) {// ���������� , sqrt(N)������ �ڿ��� div�� ���Ͽ�
		while (n % div == 0) {
			//������ =0 -> div�� N�� ��� 
			//�̶�, div���� ���� ����� ��� ó���Ǿ����Ƿ� div ���μ����� ����ȴ�.

			//���μ� ��Ͽ� div�� �߰��Ѵ�..
			factors.push_back(div);

			//N���� div�� �Ұ����ش�.
			//�׷��Ƿ� ���Ŀ��� div�� ������ ���μ��� ã�Եȴ�.
			n /= div;
		}

	}

	if (n > 1) {//���μ��� ã�� ���ϰ� �����ִ� N�� �����Ѵٸ�, �Ҽ��� �� �ۿ� ����.
		factors.push_back(n);//�̸� ���μ��� �߰��Ѵ�
	}

	return factors;
}

void process(int caseIndex) {
	int n; //���μ������� ���ڸ� �Է¹���
	scanf("%d", &n);

	vector<int> factors = factorize(n); //factorize �Լ� ȣ��

	printf("#%d:\n", caseIndex); //case ��ȣ ���
	for (int i = 0; i < factors.size(); ++i) { //�������
		if (i > 0) {
			printf(" ");
		}
		printf("%d", factors[i]); //���μ����� ��� ���
	}
	printf("\n");

}

int main() {
	int caseSize; //�׽�Ʈ���̽� �Է¹���
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex); //���μ��� �Լ� ȣ��
	}
	return 0;
}