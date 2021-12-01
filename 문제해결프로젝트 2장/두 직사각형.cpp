#include<iostream>
#include <cstdio>

using namespace std;


//������ ���ϴ� �Լ�
int get_area(int la, int ra, int ta, int ba,
	int lb, int rb, int tb, int bb)
{
	int l, r, t, b;//�����Ͽ� ���� ���簢���� �����¿�
	l = max(la, lb); //�ִ밪 = ���簢���� left��
	r = min(ra, rb); //�ּҰ� = right �� 
	t = min(ta, tb); //�ּҰ� = top ��
	b = max(ba, bb); //�ִ밪 = bottom ��


	
	if (l <= r && b <= t) //r-l, t-b�� ����̱� ���� ����(0�� �� �� ������ ���)
		return((r - l) * (t - b)); //���簢�� ���� ����

	return 0; //�Ҹ�����, ����
}

void test_case()
{
	int ax, ay, bx, by; //�� A,B�� x,y ��ǥ
	int px, py, qx, qy;//�� P,Q�� x,y ��ǥ
	//�Է¹޴´�.
	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta; //���簢�� a�� �����¿� �� ����
	la = min(ax, bx); //left ->ax�� bx�� �ּҰ�
	ra = max(ax, bx); //right ->ax�� bx�� �ִ밪
	ta = max(ay, by); //top ->->ay�� by�� �ִ밪
	ba = min(ay, by); //bottom ->ay�� by�� �ּҰ�

	int lb, rb, bb, tb; //���簢�� b��  �����¿� �� ����
	lb = min(px, qx); //left ->px�� qx�� �ּҰ�
	rb = max(px, qx); //right ->px�� qx�� �ִ밪
	tb = max(py, qy); //top ->py�� qy�� �ִ밪
	bb = min(py, qy); //bottom ->py�� qy�� �ּҰ�

	//���� ��ǥ������ ���̸� ����ϴ� get_area() ȣ��
	int answer = get_area(la, ra, ta, ba,
		lb, rb, tb, bb);

	printf("%d\n", answer); //���� ���̸� ���
}

int main() {
	int t; //�׽�Ʈ ���̽� ��
	scanf("%d", &t); //�Է¹���

	for (int i = 0; i < t; i++) { //���̽� ����ŭ test_case() ȣ��
		test_case();
	}
	return 0; //����
}

