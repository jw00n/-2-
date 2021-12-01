#include <iostream>
#include <algorithm>
#include <vector>
#include<time.h>

using namespace std;


int main() {
	clock_t start, end; //�ð� ����

	int n; //n�� �׻� 2�� �ŵ�����
	cin >> n; //�Է¹���

	int data[1024][1024]; //�ִ�ũ�� 1024



	//n���� �ٿ� ���ļ� ���� n���� �Է¹���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}

	start = clock();//��������


	while (n > 1) { //n�� 1�� �ɶ����� �ݺ�
		vector<int> temp(4);//2x2���簢�� ������ �� ����
		vector<vector<int>>result(n / 2, vector<int>(n / 2, 0)); //�ٿ������� ����� ������ ����

		//���� 2x2���簢���� ���ϰ� �� �ȿ��� 2��°�� ���� ���ڸ� ���Ѵ�.
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2 ) {
				temp[0] = data[i][j];
				temp[1] = data[i + 1][j];
				temp[2] = data[i][j + 1];
				temp[3] = data[i + 1][j + 1];

				sort(temp.begin(), temp.end()); //�������� ���� -> ���� ��, 3��° ���Ұ� ���� �ι�°�� ū ���� �ȴ�.

				result[i / 2][j / 2] = temp[2]; //�� ��°�� ū ������ ����
			}
		}
		n /= 2; //ũ��� ��� n/2*n/2�� �پ���.

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = result[i][j]; //����� ���� ��Ŀ� �����Ѵ�.
			}
		}
		

	}

	cout << data[0][0] << endl;//Ǯ����� 1*1��� ������ ���� ���� ���
	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���

	return 0;
}
