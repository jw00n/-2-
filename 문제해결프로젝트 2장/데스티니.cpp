#include<cstdio>
#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

class Point2D {
private:
	int x;
	int y;


public:
	Point2D(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;

	}


	/*
	2���� ���󿡼� �� this���� �� target���� �Ÿ��� ������ ����ϴ� �Լ�
	target
	return
	*/

	//��ǥ������ �Ÿ��� ���� ���ϰ� ����
	int getSquareDistanceTo(const Point2D& target) const {
		int dx = abs(this->x - target.x); // |x1-x2| =dx
		int dy = abs(this->y - target.y); // |y1-y2| =dy
		return dx * dx + dy * dy; //�������� ��

	}


	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSquareDistanceTo(target); //�Ÿ��� ������ ����ϴ� �Լ� ȣ��
		return sqrt(sqd); //sqrt()�� ������(=�Ÿ�)�� ���ؼ� ����
	}
};

int main() {
	int n; //õü�� ��
	Point2D* points; //����ü ����
	 
	scanf("%d", &n); //õü�� �� n�� �Է¹���
	points = new Point2D[n]; //������ŭ ����ü �迭 ����

	for (int i = 0; i < n; i++) { //n�� ��ŭ�� ��ǥ���� �Է¹޴� �ݺ���
		int x, y; 
		scanf("%d %d", &x, &y); //x,y��ǥ �Է�

		points[i] = Point2D(x, y); //Point2D�� �Ѱ���
	}

	int min_sqd = INT_MAX; //int �ִ밪���� �ʱ�ȭ
	int min_cnt = 0; //0���� �ʱ�ȭ

	for (int i = 0; i < n; i++) { //i,j�� �ߺ����� ������ �ʰԲ� ��.
		for (int j = 0; j < i; j++) { //j<i�� ������ j�� i���� ũ�Ե� ���� ���� i�� �������� �� �ߺ����� ���� �� �ֱ⶧����.
			int sqd = points[i].getSquareDistanceTo(points[j]); //i��° ��ǥ�� j��° ��ǥ�� �Ÿ��� ����
			if (sqd < min_sqd) { //���� �Ÿ��� min_sqd���� �۴ٸ�
				min_sqd = sqd; //������Ʈ
				min_cnt = 1;//1�� ����
			}
			else if (sqd == min_sqd) { //������ ���(�������� �䱸�ϴ� �ּ� �Ÿ���ŭ ������ õü �ֵ�)
				min_cnt++; //ī��Ʈ ����
			}
		}
	}


	double distance = sqrt(min_sqd);  //�ּҰŸ��� ��Ʈ��(�Ҽ���)
	printf("%.1f\n", distance); //�Ҽ��� 1°�ڸ����� ���
	printf("%d\n", min_cnt); //�ּҰŸ��� �ش��ϴ� õü �ֵ��� ���� ���

	delete[] points; 
	return 0;
}
