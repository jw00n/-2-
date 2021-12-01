#include<cstdio>
#include<iostream>

using namespace std;

int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1; // ������� -1 ���

	for (int i = n-1; i>=0; i--) 
		//������������ ���ĵǾ������Ƿ� �ڿ������� ã�°� ����
	{
		if (month[i] == m) //���� ��ġ�ϸ�
		{
			maxHeight = height[i]; //���� ū Ű �Է�
			break;
		}
	}

	return maxHeight; //month[i]== m�� ���� ū height[i]

}


/*
n ���丮�� ��
m ã�����ϴ� ��
height �� ���丮�� Ű
month �� ���丮�� ��� ��
*/

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n); //���丮�� �� �Է¹���
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++) //�������� ���е� �� ���丮�� Ű ����
	{
		scanf("%d", &height[i]); 
	}

	for(int i=0; i<n; i++) //�������� ���е� �� ���丮�� ��� �� ����
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m); //���� ���� ��Ÿ���� 1~12������ �ڿ���

	int answer = getMaximumHeight(height, month, n, m); //���� ū Ű�� ã�� �Լ�ȣ��

	printf("%d\n", answer); //���� ū Ű ���

	delete[] height;
	delete[] month;
	return 0;
}