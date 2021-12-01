#include <iostream>
#include <algorithm>
#include <vector>
#include<time.h>

using namespace std;

int table[1024][1024];//원소 N개를 입력받을 배열 1024*1024 크기



int pulling(int x, int y) {
	vector<int> temp(4);//나눠진 2x2정사각형의 원소를 임시로 저장할 벡터


	//먼저 2x2정사각형을 구하고 그 안에서 2번째로 작은 숫자를 구한다.
	for (int i = x; i < x + 2; i++) {
		for (int j = y; j < y + 2; j++) {
			temp[0] = table[i][j];
			temp[1] = table[i + 1][j];
			temp[2] = table[i][j + 1];
			temp[3] = table[i + 1][j + 1];

			sort(temp.begin(), temp.end()); //정렬시킨 후
		}
	}

	return temp[2]; //두 번째로 큰 수= 정렬 시 3번째 수
}


int main() {
	clock_t start, end; //시간 측정
	int n;//n은 항상 2의 거듭제곱
	cin >> n; //입력받음

	//n개의 줄에 걸쳐서 원소 n개를 입력받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}
	start = clock();//측정시작

	while (n > 1) { //n=1 될 때까지 반복
		for (int i = 0;i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				table[i / 2][j / 2] = pulling(i, j); //pulling의 결과 값을 넣어준다.
			}
		}
		n /= 2; //2x2정사각형으로 나눠지며 다시 반복
	}


	cout << table[0][0] << endl;//남은 마지막 숫자 출력

	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력

	return 0;

}