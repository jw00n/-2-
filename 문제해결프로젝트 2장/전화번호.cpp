#include <cstdio>

using namespace std;

const int MAX_TABLE_LENGTH = 10000;// 0~ 9999 �ִ� ���� ����

/*
data[0]~data[n-1] �� ������ ��ȣ�鿡 ���� �󵵼� ���̺��� ä��� �Լ�

param data
param n
table table[x] :=data �迭���� x�� ������ Ƚ��

*/

void fillFrequencyTable(int data[], int n, int table[])
{
	int frequent_number = 0;//�󵵼� ���� ����

	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //table ���� ��� 0���� �ʱ�ȭ
	{
		table[i] = 0;
	}

	for (int i = 0; i < n; i++) //������ ������ŭ �ݺ�
	{
		frequent_number = data[i]; //������ ���� �Է�
		table[frequent_number] += 1; //frequent_number�� �ε����� �ϴ� table ������׷��� 1�� ����
	}



}

/*
cnt �迭�� �ش��ǹ̸� �����ϵ��� �� ���� ä������
data[0] ~ data[n-1] ���̿��� ���� ���� ������ ��ȣ�� ��ȯ�ϴ� �Լ�
data 
n
return ���� ���� ������ ��ȣ, �������� ��� ���������� ���� ���� ��ȣ
*/

int getFrequentNumber(int data[], int n) {
	//0000~ 9999 �߿��� ���帹�� ������ ��ȣ�� ���غ���
	int frequent_number = 0; //0���� �ʱ�ȭ
	int table[MAX_TABLE_LENGTH]; //0~9999���� ������ Ƚ���� ī��Ʈ�ϴ� ������׷�

	fillFrequencyTable(data, n, table); //ȣ��

	for (int i = 0; i < MAX_TABLE_LENGTH; i++)
	{
		if (table[i] > table[frequent_number]) //���ؼ� table[i]�� ���� ũ�ٸ� Ƚ���� �� frequent_number�� ����Ű�� Ƚ������ �����Ƿ�
			frequent_number = i;// ������Ʈ
		/*
		���� Ƚ���� ���� ��ȣ�� �� ���� ���, 
		���� �ͺ��� ���������� �ݺ����� ���Ƽ�, Ƚ���� ���� ��ȣ�� �ڿ� ���� ���̴�. 
		Ƚ���� ���� ū ���ڴ� ���ǹ��� ���� Ƚ���� ������ ���� ���ڰ� frequent_number�� ����.
		*/	
	}
	 
	return frequent_number; //�� �� ����

} 

int main() {
	int n; //��ȭ��ȣ ���� 

	scanf("%d", &n); //n �Է¹޾� 
	int* data = new int[n]; //�迭 �Ҵ�

	for (int i = 0; i < n; i++) { //�迭�� ������ �Է¹޴� for��
		scanf("%d", &data[i]);
	}

	int answer = getFrequentNumber(data, n); //����� �����ϴ� ��ȣ ����ϴ� �Լ� ȣ��

	//�� �ڸ��� ����ϱ����� => "%04d" ex) 0 -> 0000, 999-> 0999
	printf("%04d", answer);

	delete[] data;

	return 0;
}