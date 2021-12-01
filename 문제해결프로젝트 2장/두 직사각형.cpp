#include<iostream>
#include <cstdio>

using namespace std;


//면적을 구하는 함수
int get_area(int la, int ra, int ta, int ba,
	int lb, int rb, int tb, int bb)
{
	int l, r, t, b;//교차하여 생긴 직사각형의 상하좌우
	l = max(la, lb); //최대값 = 직사각형의 left값
	r = min(ra, rb); //최소값 = right 값 
	t = min(ta, tb); //최소값 = top 값
	b = max(ba, bb); //최대값 = bottom 값


	
	if (l <= r && b <= t) //r-l, t-b가 양수이기 위한 조건(0이 될 수 있음을 고려)
		return((r - l) * (t - b)); //직사각형 넓이 리턴

	return 0; //불만족시, 종료
}

void test_case()
{
	int ax, ay, bx, by; //점 A,B의 x,y 좌표
	int px, py, qx, qy;//점 P,Q의 x,y 좌표
	//입력받는다.
	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta; //직사각형 a의 상하좌우 값 변수
	la = min(ax, bx); //left ->ax와 bx의 최소값
	ra = max(ax, bx); //right ->ax와 bx의 최대값
	ta = max(ay, by); //top ->->ay와 by의 최대값
	ba = min(ay, by); //bottom ->ay와 by의 최소값

	int lb, rb, bb, tb; //직사각형 b의  상하좌우 값 변수
	lb = min(px, qx); //left ->px와 qx의 최소값
	rb = max(px, qx); //right ->px와 qx의 최대값
	tb = max(py, qy); //top ->py와 qy의 최대값
	bb = min(py, qy); //bottom ->py와 qy의 최소값

	//구한 좌표값으로 넓이를 계산하는 get_area() 호출
	int answer = get_area(la, ra, ta, ba,
		lb, rb, tb, bb);

	printf("%d\n", answer); //구한 넓이를 출력
}

int main() {
	int t; //테스트 케이스 수
	scanf("%d", &t); //입력받음

	for (int i = 0; i < t; i++) { //케이스 수만큼 test_case() 호출
		test_case();
	}
	return 0; //종료
}

