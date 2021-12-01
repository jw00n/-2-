#include<cstdio>
#include<iostream>

using namespace std;


/*
�־��� �迭�� ������������ �˻��ϴ� �Լ�
data �Է¹��� �л����� Ű ���� �迭
n �������� ��
return ���� T or F
*/
bool isOrdered(int data[], int n)
{
	int count = 0; 

	for (int i = 0; i < n-1; i++) { //��Ƚ���� �����Ͽ� i�� n-1 �̸�����. n�����ϸ� �迭���� �Ѵ� ���� �߻�
		if (data[i] > data[i + 1]) //i��°�� j+1��°�� ���ϸ� ������������ Ȯ��
		{
			count++; //i��°�� �� ũ�ٸ� count 1����
			break;
		}
	}

	if (count > 0) //�ϳ��� �ִ� ��� false
		return false;
	else //���ٸ� ���������̹Ƿ� true
		return true;

}

int main()
{
	int n;
	int* data;

	scanf("%d", &n); //�л� �� �Է�
	data = new int[n]; //�л� �� n��ŭ �迭�Ҵ�

	for (int i = 0; i < n; i++) //�ݺ����� ���� data[i]�� n���� �� �л��� Ű�� ����
	{
		scanf("%d", &data[i]);
	}

	bool result = isOrdered(data, n); //�������� ���θ� Ȯ���ϴ� �Լ� ȣ��

	if (result) //TRUE�� ���
	{
		printf("YES");
	}
	else { //FALSE�� ���
		printf("NO");
	}

	delete[] data;
	return 0;
}