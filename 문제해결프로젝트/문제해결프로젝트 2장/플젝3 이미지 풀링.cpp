#include <iostream>
#include <algorithm>
#include <vector>
#include<time.h>

using namespace std;

int table[1024][1024];//���� N���� �Է¹��� �迭 1024*1024 ũ��



int pulling(int x, int y) {
	vector<int> temp(4);//������ 2x2���簢���� ���Ҹ� �ӽ÷� ������ ����


	//���� 2x2���簢���� ���ϰ� �� �ȿ��� 2��°�� ���� ���ڸ� ���Ѵ�.
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			temp[0] = table[i][j];
			temp[1] = table[i + 1][j];
			temp[2] = table[i][j + 1];
			temp[3] = table[i + 1][j + 1];

			sort(temp.begin(), temp.end()); //���Ľ�Ų ��
		}
	}

	return temp[2]; //�� ��°�� ū ��= ���� �� 3��° ��
}


int main() {
	clock_t start, end; //�ð� ����
	int n;//n�� �׻� 2�� �ŵ�����
	cin >> n; //�Է¹���

	//n���� �ٿ� ���ļ� ���� n���� �Է¹���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}
	start = clock();//��������

	while (n > 1) { //n=1 �� ������ �ݺ�
		for (int i = 0;i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				table[i / 2][j / 2] = pulling(i, j); //pulling�� ��� ���� �־��ش�.
			}
		}
		n /= 2; //2x2���簢������ �������� �ٽ� �ݺ�
	}


	cout << table[0][0] << endl;//���� ������ ���� ���

	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���

	return 0;

}