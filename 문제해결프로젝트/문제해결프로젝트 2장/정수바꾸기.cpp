#include <iostream>
#include <algorithm>
#include<time.h>

using namespace std;

long long min_count = 1.e+18; //10^9의 제곱값, 비교횟수 제일 최댓값으로 초기화

/*
A는 B보다 작은 값

가능한 연산
1) 2를 곱한다
2) 맨 끝자리에 1를 추가한다. 즉, (*10 + 1)라는 뜻.

BFS 방법으로 탐색
트리를 따라 탐색하므로 각각 A,B,count를 넘겨줌 
*/

void BFS(long long A, long long B, long long count) {
	
	if (A > B) return;//A가 B보다 크게 된 경우는 종료시킨다.
	
	else if (A == B) { //A와 B가 일치한 경우, 현 count의 값과 최솟값과 비교하여 더 작은 값을 저장한다.
		min_count = min(min_count, count); 
	}

	//함수를 호출하는 횟수 = 필요한 연산의 횟수
	BFS(A * 2, B, count + 1);  //연산 1) 2를 곱한다.
	BFS(A * 10 + 1, B, count + 1); //연산 2) 숫자 끝에 1을 추가한다.
}

int main()
{
	clock_t start, end; //시간 측정

	long long A, B; //정수 A,B
	long long count = 1;  //비교횟수는 함수를 부르는것부터 1번이므로 1로 시작.
	cin >> A >> B; //A, B를 입력받음

	start = clock();//측정 시작
	BFS(A, B, count);  //BFS 함수 호출

	if (min_count == 1.e+18) //최대횟수까지 비교했음에도 바꿀수 없다면 
		cout << "-1" << endl; //-1 출력
	else
		cout << min_count << endl; //횟수 출력

	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력

	return 0;
}