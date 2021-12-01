#include<cstdio>
#include<iostream>

using namespace std;

/*
�ߺ��� ������ ������ ������ ���� ����ϴ� �Լ�
data ���� �迭
n ���� �迭 ũ��
return ���� ������ ������ ��
*/

int getElementTypeCount(int data[], int n)
{
	int countType = 0; //������ȣ ������ �� �����ϴ� ����

	for (int i = 1; i < n; i++) //-1���� ���� �� �����Ƿ� i=1���� ����
	{//�ߺ� �ƴҶ��� ���� �� ����, ������������ ���ĵ����Ƿ� 1 2 1 ���� ��� �߻�X
		if (data[i - 1] != data[i])//�ߺ�Ȯ���� data[i-1]�� data[i]�� ����ġ ��	
			countType++; //����ġ�ϴٸ� ������ �� ���� +1
	}
	
	return countType+1; //��Ƚ���� +1 �������Ѿ� ���� ���� ��ġ. �⺻ ������ ���� 1�̻�

}

int main()
{
	int n; //���� �迭�� ũ��(ȭ���� ��)
	int* data; //���� �迭

	scanf("%d", &n); //������ ���� �Է¹���
	data = new int[n]; //�迭ũ�� �Ҵ�

	for (int i = 0; i < n; i++) // ������ȣ�� �������� �����Ͽ� 
	{
		scanf("%d", &data[i]); //�迭�� ����
	}

	int answer = getElementTypeCount(data, n); //�ߺ��� ������ ������ ������ ���� ����ϴ� �Լ� ȣ��
	printf("%d\n", answer); //���

	delete[] data;
	return 0;

}
