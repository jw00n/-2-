#include<cstdio>
#include<iostream>

using namespace std;

/*
���� �Ʒ� ��ǥ�� (x,y)�� �ȼ��� ������ R�� ���� ���ԵǴ°�?
x
y
R -���� �������� �ȼ��� R
return ���Եȴٸ� true, else false

*/

bool isInside(long long x, long long y, long long R)
{
	//x^2+y^2 < R^2 
	//������ (x,y)���� �Ÿ��� ������ �������� �������� �۴ٸ� �� �ȿ� ����.
	long long sqd = x * x + y * y;
	if (sqd < R * R) return true; //true = �� �ȿ� ����
	return false; //�� �ۿ� ����

}

void testcase(int caseIndex) {
	long long R; //������ ing���� ����Ƿ� longŸ������ ���� 
				 //longŸ�� R�� scanf�� �Է¹������� long long���� �Է¹���
	scanf("%lld", &R); //������ �Է�
	 
	long long sum = 0; //1��и鿡 �����ϴ� �� �ȼ��Ǽ� (*4�ϸ� ��� ��и� �ȼ��� ���Ҽ�����)
	long long y = R; //y���� R�� �ʱ�ȭ
	for (long x = 0; x <= R; x++) { //0���� R���� ����
		long long height = 0;
		for (; y >= 0; y--) {//y�� �� R���� 0���� -1�� �Ǹ� ���������� �������ٰ� 
			if (isInside(x, y, R)) { //�ȼ��� ���ȿ� �ִ��� ���θ� �Ǵ��ϰ� 
				//���� ���ʷ� �� �ȿ� ���Ե� �ȼ�(x,y)�ִٸ� ���ϴ� ���� ���ȿ� �ִ�.
				//�� �׷��� ���̴� y+1
				height = (y + 1); //height = x�࿡ �ִ� �ȼ� ��
				break;
			}
		}
		sum += height; //������ ������ sum�� 1��и��� �ȼ� ���� ��ġ�ϰ� �ȴ�. �ʺ�� 1�̹Ƿ�
	}
	printf("#%d\n", caseIndex); //�ε��� ���
	printf("%lld\n", sum * 4); //��� ��и��� �ȼ� ��
}

int  main()
{
	int caseSize; //�׽�Ʈ ���̽��� �� ����
	scanf("%d", &caseSize); //�׽�Ʈ ���̽� �� �Է¹���
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex); //�׽�Ʈ ���̽� �Լ� ȣ��
	}
	return 0;
}