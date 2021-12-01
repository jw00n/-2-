#include <iostream>
#include <string.h>
#include <deque>
#include<time.h>


using namespace std;

deque<int> dq[4]; //��Ϲ��� ���� ���� ť
int rotate_num; //ȸ�� Ƚ��
bool check[4] = { 0,0,0,0 }; //��Ϲ��� �湮 Ȯ�ο�, 0���� �ʱ�ȭ
int gear, direct; //��Ϲ��� ��ȣ�� ȸ������
int sum = 0; //�հ�
int result = 1;

//������� ȸ��(ť�� ���Ի���)�ϸ� ���¸� �ٲ��ִ� �Լ�
void change(int gear, int direct) {
	if (direct == 1) { //�ð�����϶�
		int temp = dq[gear].back(); //��� ������ ���� ���¸� temp�� ����
		dq[gear].pop_back(); //������ �� ����
		dq[gear].push_front(temp); //�� �տ� ����
	}

	else { //�ݽð�����϶�
		int temp = dq[gear].front(); //��� ù��° ���� ���¸� temp�� ����
		dq[gear].pop_front(); //ù��°  �� ����
		dq[gear].push_back(temp); //�� �ڿ� ����
	}

}

/*
��Ϲ����� ����, ������ ���� ȸ�� ������ �������ִ� �Լ�
*/
void rotate(int gear, int direct) {
	check[gear] = 1; //�ش� ��Ϲ��� �湮�Ѱ����� �ٲ�

	if (gear != 0) { //2,3,4��°�� ��Ϲ����� ���
		if (dq[gear - 1][2] != dq[gear][6] && !check[gear - 1]) { //���� ��Ͽ� �� ��ϰ� ���� N�� S�� �ٸ��� ���� ��ϰ� �湮���� �������̶��
			rotate(gear - 1, direct * (-1)); //�� ��Ͽ� �ݴ�������� ���ư�����
		}
	}

	if (gear != 3) { //1,2,3��°�� ��Ϲ����� ���
		if (dq[gear + 1][6] != dq[gear][2] && !check[gear + 1]) { //���� ��Ͽ� �� ��ϰ� N�� S�� �ٸ��� ���� ��ϰ� �湮���� �������̶��
			rotate(gear + 1, direct * (-1));//�� ��Ͽ� �ݴ�������� ���ư����ϴ� �μ��� �Ѱ��ְ� rotate�Լ��� �ҷ��´�.
		}
	}

	change(gear, direct);  //��Ϲ��� ȸ���� ���� ���� �����ϴ� �Լ� ȣ��

}


int main() {
	clock_t start, end; //�ð� ����

	string state; //��ϻ��¸� ���� 

	for (int i = 0; i < 4; i++) { //4���� ��Ϲ��� 8���� ���� ���� ����
		cin >> state;
		for (int j = 0; j < 8; j++) {
			dq[i].push_back((state[j] - '0'));
		}
	}

	cin >> rotate_num; //5��° �Է��� ȸ�� Ƚ�� �Է�
	start = clock();//���� ����

	for (int i = 0; i < rotate_num; i++) {
		cin >> gear >> direct; //ȸ���� ��Ϲ��� ��ȣ(1~4)��, ����(1,-1)�� �Է¹޴´�.

		rotate(gear - 1, direct); //ȸ����ų �Լ� ȣ��, 0~3�̹Ƿ� -1�ؼ� �Ѱ���
		memset(check, 0, sizeof(check)); //������ �湮Ȯ�ο� �迭 check�� �ٽ� 0���� �ʱ�ȭ
	}


	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 1) { //4���� ��Ϲ����� 0��° ����(=12�� ����)�� S��(=1)�̶��
			sum += result; //�հ迡 ������ ����
		}
		result *= 2; //1,2,4,8�� ����
	}




	cout << sum << endl; //�հ����


	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���


	return 0;
}
