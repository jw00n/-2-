#include <iostream>
#include <algorithm>
#include<time.h>

using namespace std;

long long min_count = 1.e+18; //10^9�� ������, ��Ƚ�� ���� �ִ����� �ʱ�ȭ

/*
A�� B���� ���� ��

������ ����
1) 2�� ���Ѵ�
2) �� ���ڸ��� 1�� �߰��Ѵ�. ��, (*10 + 1)��� ��.

BFS ������� Ž��
Ʈ���� ���� Ž���ϹǷ� ���� A,B,count�� �Ѱ��� 
*/

void BFS(long long A, long long B, long long count) {
	
	if (A > B) return;//A�� B���� ũ�� �� ���� �����Ų��.
	
	else if (A == B) { //A�� B�� ��ġ�� ���, �� count�� ���� �ּڰ��� ���Ͽ� �� ���� ���� �����Ѵ�.
		min_count = min(min_count, count); 
	}

	//�Լ��� ȣ���ϴ� Ƚ�� = �ʿ��� ������ Ƚ��
	BFS(A * 2, B, count + 1);  //���� 1) 2�� ���Ѵ�.
	BFS(A * 10 + 1, B, count + 1); //���� 2) ���� ���� 1�� �߰��Ѵ�.
}

int main()
{
	clock_t start, end; //�ð� ����

	long long A, B; //���� A,B
	long long count = 1;  //��Ƚ���� �Լ��� �θ��°ͺ��� 1���̹Ƿ� 1�� ����.
	cin >> A >> B; //A, B�� �Է¹���

	start = clock();//���� ����
	BFS(A, B, count);  //BFS �Լ� ȣ��

	if (min_count == 1.e+18) //�ִ�Ƚ������ ���������� �ٲܼ� ���ٸ� 
		cout << "-1" << endl; //-1 ���
	else
		cout << min_count << endl; //Ƚ�� ���

	end = clock(); //���� ���� 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //�ð� �ʴ����� ���

	return 0;
}