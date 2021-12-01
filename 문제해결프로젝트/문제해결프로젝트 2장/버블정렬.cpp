#include<cstdio>
#include<iostream>

using namespace std;

void bubbleSort(int data[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		int negativecount = 0; //���������� �����ϴ� ���� ��
		for (int j = 0; j < n - 1 - i;j++) {//i�� �ѹ��� �ݺ��ɶ����� ������ ���� ���� ���� ���Ƿ� n-1���� n-1-i������ �ݺ��ϸ� �ȴ�.
		//���������� �����ϴ� ���� ������ 2�� ���� �ڸ��� ��ȯ
			
			if (data[j] > data[j + 1]) {
				
				//j��°�� j+1��°���� ũ�ٸ� ���������� �ƴ�
				int tmp = data[j];
				data[j] = data[j + 1]; //��ȯ
				data[j + 1] = tmp;
				negativecount++;
			}
			
		}
		if (negativecount == 0) //ó������ ���ĵ� ���¶��
			break;
	}
	
}


int main()
{
	int n; //�������� ����
	int* data; //������ �迭 ����

	scanf("%d", &n); //���� �Է¹ް�
	data = new int[n]; //������ŭ �迭 �Ҵ�

	for (int i = 0;i < n; i++) //�迭�� ���� �Է�
	{
		scanf("%d", &data[i]);
	}

	bubbleSort(data, n); //��������  ����

	for (int i = 0; i < n; i++) //������ �����
	{
		if (i > 0)
		{
			printf(" "); //���ڻ��̿� ������ �־
		}
		printf("%d", data[i]); //���ĵ� data �迭�� ���
	}

	delete[] data;
	return 0;
}