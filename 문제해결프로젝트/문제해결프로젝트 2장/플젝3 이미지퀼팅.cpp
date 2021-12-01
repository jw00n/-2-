#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

int h, w; //h= ���� , w= �ʺ�

//�� �迭�� �޾� ssd ����ϴ� �Լ�
vector<int> subtract(vector<vector<int>>arrB1, vector<vector<int>>arrB2) {
	vector<int> possibleTree(w); //������ ��� ���밪 �� ����
	vector<vector<int>>result(h, vector<int>(w, 0)); //���밪 ��� ����


	int row_count = arrB1.size(); //�� ��
	int col_count = arrB1[0].size();  //�� ��

//�� ���밪�� ��������  ����
	for (int i = 0; i < row_count; i++) {
		for (int j = 0;j < col_count; j++) {
			result[i][j] = abs(arrB1[i][j] - arrB2[i][j]) * abs(arrB1[i][j] - arrB2[i][j]);
			
		}
	}

	//0���� ���� �̸� �����صд�.
	for (int i = 0; i < w; i++) {
		possibleTree[i] = result[0][i];
	}


	for (int x = 0; x < col_count; x++) {
		int col = x;
		int row = 0;

		while (row < row_count-1) { //row�� row_count-1���� �ݺ�

			//���� ���� ��
			if (col == 0) {
				if (result[row + 1][col] < result[row + 1][col + 1]) {//������ �� ������
					possibleTree[x] += result[row + 1][col];//���� �����ְ�
					row++; //row ������ �̵�
					continue;

				}
				else { //�������� �� ������
					possibleTree[x] += result[row + 1][col + 1];//������ ���� �����ְ�
					row++;//�ش� ���ҷ� �̵��ؼ� �ݺ�
					col++;
					continue;
				}
			}
			//���� ���� ��
			else if (col == col_count - 1) {
				if (result[row + 1][col - 1] < result[row + 1][col]) {//������ �� ������
					possibleTree[x] += result[row + 1][col - 1];
					row++;
					col--;
					continue;
				}
				else { //�������� �� ������
					possibleTree[x] += result[row + 1][col];
					row++;
					continue;
				}
			}

			//�Ϲ����� ���(-1,0,1 ��� �̵� ����)
			else {
				
				//-1�� ���� ���� ���� ���
				if (result[row + 1][col - 1] < result[row + 1][col] && result[row + 1][col - 1] < result[row + 1][col + 1]){			
					possibleTree[x] += result[row + 1][col-1];
					row++;
					col--;
					continue;
				}

				//0�� ���� ���� ���� ���
				else if (result[row + 1][col] < result[row + 1][col-1] && result[row + 1][col] < result[row + 1][col + 1]) {
					possibleTree[x] += result[row + 1][col];
					row++;
					continue;
				}

				//+1�� ���� ���� ���� ���
				else {
					possibleTree[x] += result[row + 1][col+1];
					row++;
					col++;
					continue;
				}

			}

		}
	}

	return possibleTree;//��� ����
}



int main() {
	clock_t start, end; //�ð� ����
	// h= ������ �� �̹����� ���� (1~100) / w= ������ �ʺ�(1~100)
	cin >> h >> w; //�Է��� �޴´�.

	vector<vector<int>>arrB1(h, vector<int>(w, 0)); //B1
	vector<vector<int>>arrB2(h, vector<int>(w, 0));// B2


	

	//B1�� �Է¹޴´�.
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB1[i][j];
		}
	}

	//B2�� �Է¹޴´�.
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB2[i][j];
		}
	}
	start = clock();//��������

	vector<int> answers = subtract(arrB1, arrB2); //ssd����ϴ� �Լ� ȣ��

	int SSD = *min_element(answers.begin(), answers.end()); //�������� ã�Ƽ� ���
	cout << SSD << endl; 

	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���
	
	return 0;
}