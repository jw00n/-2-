#include<cstdio>
#include<iostream>

using namespace std;

/*
왼쪽 아래 좌표가 (x,y)인 픽셀이 반지름 R인 원에 포함되는가?
x
y
R -원의 반지름의 픽셀수 R
return 포함된다면 true, else false

*/

bool isInside(long long x, long long y, long long R)
{
	//x^2+y^2 < R^2 
	//원점과 (x,y)사이 거리의 제곱이 반지름의 제곱보다 작다면 원 안에 있음.
	long long sqd = x * x + y * y;
	if (sqd < R * R) return true; //true = 원 안에 있음
	return false; //원 밖에 있음

}

void testcase(int caseIndex) {
	long long R; //반지름 ing형을 벗어나므로 long타입으로 선언 
				 //long타입 R을 scanf로 입력받으려면 long long으로 입력받음
	scanf("%lld", &R); //반지름 입력
	 
	long long sum = 0; //1사분면에 존재하는 총 픽셀의수 (*4하면 모든 사분면 픽셀수 구할수있음)
	long long y = R; //y값을 R로 초기화
	for (long x = 0; x <= R; x++) { //0부터 R까지 증가
		long long height = 0;
		for (; y >= 0; y--) {//y는 값 R부터 0으로 -1씩 되며 위에서부터 내려오다가 
			if (isInside(x, y, R)) { //픽셀이 원안에 있는지 여부를 판단하고 
				//가장 최초로 원 안에 포함된 픽셀(x,y)있다면 이하는 전부 원안에 있다.
				//이 그룹의 높이는 y+1
				height = (y + 1); //height = x축에 있는 픽셀 수
				break;
			}
		}
		sum += height; //누적이 끝나면 sum은 1사분면의 픽셀 수와 일치하게 된다. 너비는 1이므로
	}
	printf("#%d\n", caseIndex); //인덱스 출력
	printf("%lld\n", sum * 4); //모든 사분면의 픽셀 수
}

int  main()
{
	int caseSize; //테스트 케이스의 수 변수
	scanf("%d", &caseSize); //테스트 케이스 수 입력받음
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex); //테스트 케이스 함수 호출
	}
	return 0;
}