#include <iostream>
#include <string.h>
#include <deque>
#include<time.h>


using namespace std;

deque<int> dq[4]; //톱니바퀴 상태 저장 큐
int rotate_num; //회전 횟수
bool check[4] = { 0,0,0,0 }; //톱니바퀴 방문 확인용, 0으로 초기화
int gear, direct; //톱니바퀴 번호와 회전방향
int sum = 0; //합계
int result = 1;

//방향따라서 회전(큐에 삽입삭제)하며 상태를 바꿔주는 함수
void change(int gear, int direct) {
	if (direct == 1) { //시계방향일때
		int temp = dq[gear].back(); //톱니 마지막 극의 상태를 temp에 저장
		dq[gear].pop_back(); //마지막 극 삭제
		dq[gear].push_front(temp); //맨 앞에 삽입
	}

	else { //반시계방향일때
		int temp = dq[gear].front(); //톱니 첫번째 극의 상태를 temp에 저장
		dq[gear].pop_front(); //첫번째  극 삭제
		dq[gear].push_back(temp); //맨 뒤에 삽입
	}

}

/*
톱니바퀴의 좌측, 우측에 따라서 회전 방향을 결정해주는 함수
*/
void rotate(int gear, int direct) {
	check[gear] = 1; //해당 톱니바퀴 방문한것으로 바꿈

	if (gear != 0) { //2,3,4번째의 톱니바퀴일 경우
		if (dq[gear - 1][2] != dq[gear][6] && !check[gear - 1]) { //왼쪽 톱니와 현 톱니가 극이 N과 S로 다르고 좌측 톱니가 방문하지 않은것이라면
			rotate(gear - 1, direct * (-1)); //현 톱니와 반대방향으로 돌아가게함
		}
	}

	if (gear != 3) { //1,2,3번째의 톱니바퀴일 경우
		if (dq[gear + 1][6] != dq[gear][2] && !check[gear + 1]) { //왼쪽 톱니와 현 톱니가 N과 S로 다르고 우측 톱니가 방문하지 않은것이라면
			rotate(gear + 1, direct * (-1));//현 톱니와 반대방향으로 돌아가게하는 인수를 넘겨주고 rotate함수를 불러온다.
		}
	}

	change(gear, direct);  //톱니바퀴 회전에 따라 상태 변경하는 함수 호출

}


int main() {
	clock_t start, end; //시간 측정

	string state; //톱니상태를 받음 

	for (int i = 0; i < 4; i++) { //4개의 톱니바퀴 8가지 극의 상태 저장
		cin >> state;
		for (int j = 0; j < 8; j++) {
			dq[i].push_back((state[j] - '0'));
		}
	}

	cin >> rotate_num; //5번째 입력줄 회전 횟수 입력
	start = clock();//측정 시작

	for (int i = 0; i < rotate_num; i++) {
		cin >> gear >> direct; //회전할 톱니바퀴 번호(1~4)와, 방향(1,-1)을 입력받는다.

		rotate(gear - 1, direct); //회전시킬 함수 호출, 0~3이므로 -1해서 넘겨줌
		memset(check, 0, sizeof(check)); //끝나면 방문확인용 배열 check를 다시 0으로 초기화
	}


	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 1) { //4개의 톱니바퀴의 0번째 원소(=12시 방향)가 S극(=1)이라면
			sum += result; //합계에 점수를 더함
		}
		result *= 2; //1,2,4,8로 증가
	}




	cout << sum << endl; //합계출력


	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력


	return 0;
}
