#include <iostream>
#include <algorithm>
#include <vector>
#include<time.h>

using namespace std;


int main() {
	clock_t start, end; //시간 측정

	int n; //n은 항상 2의 거듭제곱
	cin >> n; //입력받음

	int data[1024][1024]; //최대크기 1024



	//n개의 줄에 걸쳐서 원소 n개를 입력받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}

	start = clock();//측정시작


	while (n > 1) { //n이 1이 될때까지 반복
		vector<int> temp(4);//2x2정사각형 역할을 할 벡터
		vector<vector<int>>result(n / 2, vector<int>(n / 2, 0)); //줄여나가며 결과를 저장할 벡터

		//먼저 2x2정사각형을 구하고 그 안에서 2번째로 작은 숫자를 구한다.
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2 ) {
				temp[0] = data[i][j];
				temp[1] = data[i + 1][j];
				temp[2] = data[i][j + 1];
				temp[3] = data[i + 1][j + 1];

				sort(temp.begin(), temp.end()); //오름차순 정렬 -> 정렬 후, 3번째 원소가 가장 두번째로 큰 수가 된다.

				result[i / 2][j / 2] = temp[2]; //두 번째로 큰 수만을 저장
			}
		}
		n /= 2; //크기는 계속 n/2*n/2로 줄어든다.

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = result[i][j]; //결과를 기존 행렬에 전달한다.
			}
		}
		

	}

	cout << data[0][0] << endl;//풀링결과 1*1행렬 마지막 남은 숫자 출력
	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력

	return 0;
}
