#include <cstdio>
#include<vector>

using namespace std;

const int MAX_N = 1000000; //�ִ� N�� ��
vector<int> FIBONACCI_TABLE; //���������̳ʷ� �������� ����

/*
�Ǻ���ġ ������ 1~ n��° ���� �迭�� �����Ͽ� ��ȯ���ִ� �Լ� 
��, ���� ���� �� 8�ڸ����� ����
param n
return fibo[i] := �Ǻ���ġ ������ i��° ��

*/

vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; 

	//�Ǻ���ġ �迭�� �̸� ���� n+1�� ������ 1������ �����ϱ⶧����
	vector<int> ret(n + 1);
	ret[1] = 0; //1���� 0 
	ret[2] = 1; //2���� 1


	//3�׺��ʹ� �Ǻ���ġ�� ���Ǹ� �̿��� ���
	//f(n) =f(n-1)+f(n-2)
	for (int i = 3; i <= n; ++i) {
		ret[i] = ret[i - 1] + ret[i - 2];

		/*
		�Ǻ���ġ�� ���Ҷ� ��ⷯ ���� �̿��� ������ 8�ڸ����� ���⵵�� ���ش�.
		((A% MOD) + (B % MOD)) % MOD == (A+B) % MOD
		�� ���� �����ϱ� ������ �Ǻ���ġ�� ���� �߸��� ���� ����.
		*/
		ret[i] %= MOD; //������ 8�ڸ����� ����
	}
	return ret; //������ 8�ڸ� ����
}

/*
�Ǻ���ġ ������ n ���� ��ȯ�ϴ� �Լ�
��, ���� ���� �� 8�ڸ����� ��ȯ
param n
return
*/
int getFibo(int n) {
	//�Ǻ���ġ�� ���� �̸� ����ص����Ƿ� �� ���� ��ȯ�Ѵ�.
	//1���� �ε����� 0�̹Ƿ� -1�� ���ش�.
	int answer = FIBONACCI_TABLE[n];//����Ǿ��ִ� n���� ������ 8�ڸ� ���� �Է�
	return answer; //����
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N); 
	//��ó���� ���� �̸� ���

	int caseSize; //�׽�Ʈ ���̽� �� 
	scanf("%d", &caseSize);//�Է¹���
	
	for (int caseIndex = 1; caseIndex<=caseSize; ++caseIndex) { //���̽� ����ŭ �ݺ��ϸ�
		int n; //� �� n�� �Է¹���
		scanf("%d", &n);

		//�Ǻ���ġ ������ n���� ����Ͽ� ������8�ڸ� ���
		int answer = getFibo(n); 
		printf("ANSWER = %d\n", answer);
	}

	//���ʿ��� �迭�� �����ϸ� �Ҵ��������ִ� ���� ����.
	FIBONACCI_TABLE.clear();

	return 0;

}

