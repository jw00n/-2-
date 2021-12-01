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
	2차원 평면상에서 점 this부터 점 target까지 거리의 제곱을 계산하는 함수
	target
	return
	*/

	//좌표사이의 거리의 제곱 구하고 리턴
	int getSquareDistanceTo(const Point2D& target) const {
		int dx = abs(this->x - target.x); // |x1-x2| =dx
		int dy = abs(this->y - target.y); // |y1-y2| =dy
		return dx * dx + dy * dy; //제곱값의 합

	}


	double getDistanceTo(const Point2D& target) const {
		double sqd = (double)this->getSquareDistanceTo(target); //거리의 제곱을 계산하는 함수 호출
		return sqrt(sqd); //sqrt()로 제곱근(=거리)을 구해서 리턴
	}
};

int main() {
	int n; //천체의 수
	Point2D* points; //구조체 선언
	 
	scanf("%d", &n); //천체의 수 n을 입력받음
	points = new Point2D[n]; //개수만큼 구조체 배열 선언

	for (int i = 0; i < n; i++) { //n개 만큼의 좌표값을 입력받는 반복문
		int x, y; 
		scanf("%d %d", &x, &y); //x,y좌표 입력

		points[i] = Point2D(x, y); //Point2D에 넘겨줌
	}

	int min_sqd = INT_MAX; //int 최대값으로 초기화
	int min_cnt = 0; //0으로 초기화

	for (int i = 0; i < n; i++) { //i,j로 중복으로 비교하지 않게끔 함.
		for (int j = 0; j < i; j++) { //j<i인 이유는 j가 i보다 크게된 경우는 다음 i가 증가했을 때 중복없이 비교할 수 있기때문에.
			int sqd = points[i].getSquareDistanceTo(points[j]); //i번째 좌표와 j번째 좌표의 거리를 구함
			if (sqd < min_sqd) { //구한 거리가 min_sqd보다 작다면
				min_sqd = sqd; //업데이트
				min_cnt = 1;//1로 선언
			}
			else if (sqd == min_sqd) { //동일한 경우(문제에서 요구하는 최소 거리만큼 떨어진 천체 쌍들)
				min_cnt++; //카운트 증가
			}
		}
	}


	double distance = sqrt(min_sqd);  //최소거리의 루트값(소수형)
	printf("%.1f\n", distance); //소수점 1째자리까지 출력
	printf("%d\n", min_cnt); //최소거리에 해당하는 천체 쌍들의 개수 출력

	delete[] points; 
	return 0;
}
