#include<cstdio>
#include<iostream>

using namespace std;

/*
�迭�� N���� ���Ұ� �������� ���� ������ ǥ���� �� �ִ��� �Ǵ��ϴ� �Լ�
data
n
return n

�������� ���� - �׻� i��° ������ ���� i+1��° ���ں��� 1�� ���� ������ �̷���� ������ �ǹ�

�������� �����̶�� �ִ� �� - �ּ� ���� n-1(�迭ũ��-1)�� ��ġ�ؾ� ���� ����

*/

bool isConsecutive(int data[], int n)
{
	//ù��° ���ҷ� �ʱ�ȭ
	int max_data = data[0]; 
	int min_data = data[0];

	//max-min=n-1���� �Ǵ��ؾ���.
	for (int i = 0; i < n; i++) //�ִ�, �ּҸ� ���ϴ� �ݺ���
	{
		if (max_data <data[i]) //max_data�� i��° ���Һ��� �۴ٸ�
			max_data = data[i]; //i��° ���ҷ� ������Ʈ
		
		//max_data�� min_data�� �����̹Ƿ� �� ���ǹ� ��� ����� �� �����Ƿ� else ������� ����.
		if (min_data > data[i])  //min_data�� i��° ���Һ��� ũ�ٸ�
			min_data = data[i]; //i��° ���ҷ� ������Ʈ
	}

	if (max_data-min_data == n - 1) 
		return true;//���ٸ� ������
	else
		return false;//�ƴ϶�� �ҿ�����
}

int main()
{
	int n; //���Ǽҵ��� �� n
	int* data;//�迭 

	scanf("%d", &n); //n �Է¹���
	data = new int[n]; //n��ŭ �迭 �Ҵ�

	for (int i = 0; i < n; i++)//�迭�� ���Ǽҵ��� ��ȣ �Է� ����
	{
		scanf("%d", &data[i]);
	}

	bool result = isConsecutive(data, n); //�����ϸ� ���ӵ� ������ ǥ���� �� �ִ��� ���� �Ǻ�

	if (result) //ǥ���� �� ����
	{
		printf("YES");
	}
	else { //ǥ���� �� ����
		printf("NO");
	}

	delete[] data;
	return 0;
}