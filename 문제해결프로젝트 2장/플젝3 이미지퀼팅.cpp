#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

int h, w; //h= 높이 , w= 너비

//두 배열을 받아 ssd 계산하는 함수
vector<int> subtract(vector<vector<int>>arrB1, vector<vector<int>>arrB2) {
	vector<int> possibleTree(w); //가능한 경로 절대값 합 저장
	vector<vector<int>>result(h, vector<int>(w, 0)); //절대값 계산 저장


	int row_count = arrB1.size(); //행 값
	int col_count = arrB1[0].size();  //열 값

//각 절대값의 제곱값을  저장
	for (int i = 0; i < row_count; i++) {
		for (int j = 0;j < col_count; j++) {
			result[i][j] = abs(arrB1[i][j] - arrB2[i][j]) * abs(arrB1[i][j] - arrB2[i][j]);
			
		}
	}

	//0행의 값은 미리 저장해둔다.
	for (int i = 0; i < w; i++) {
		possibleTree[i] = result[0][i];
	}


	for (int x = 0; x < col_count; x++) {
		int col = x;
		int row = 0;

		while (row < row_count-1) { //row가 row_count-1까지 반복

			//제일 좌측 열
			if (col == 0) {
				if (result[row + 1][col] < result[row + 1][col + 1]) {//왼쪽이 더 작을때
					possibleTree[x] += result[row + 1][col];//값을 더해주고
					row++; //row 증가로 이동
					continue;

				}
				else { //오른쪽이 더 작을때
					possibleTree[x] += result[row + 1][col + 1];//오른쪽 값을 더해주고
					row++;//해당 원소로 이동해서 반복
					col++;
					continue;
				}
			}
			//가장 우측 열
			else if (col == col_count - 1) {
				if (result[row + 1][col - 1] < result[row + 1][col]) {//왼쪽이 더 작을때
					possibleTree[x] += result[row + 1][col - 1];
					row++;
					col--;
					continue;
				}
				else { //오른쪽이 더 작을때
					possibleTree[x] += result[row + 1][col];
					row++;
					continue;
				}
			}

			//일반적인 경우(-1,0,1 모두 이동 가능)
			else {
				
				//-1의 값이 가장 작은 경우
				if (result[row + 1][col - 1] < result[row + 1][col] && result[row + 1][col - 1] < result[row + 1][col + 1]){			
					possibleTree[x] += result[row + 1][col-1];
					row++;
					col--;
					continue;
				}

				//0의 값이 가장 작은 경우
				else if (result[row + 1][col] < result[row + 1][col-1] && result[row + 1][col] < result[row + 1][col + 1]) {
					possibleTree[x] += result[row + 1][col];
					row++;
					continue;
				}

				//+1의 값이 가장 작은 경우
				else {
					possibleTree[x] += result[row + 1][col+1];
					row++;
					col++;
					continue;
				}

			}

		}
	}

	return possibleTree;//결과 리턴
}



int main() {
	clock_t start, end; //시간 측정
	// h= 포개진 두 이미지의 높이 (1~100) / w= 영역의 너비(1~100)
	cin >> h >> w; //입력을 받는다.

	vector<vector<int>>arrB1(h, vector<int>(w, 0)); //B1
	vector<vector<int>>arrB2(h, vector<int>(w, 0));// B2


	

	//B1에 입력받는다.
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB1[i][j];
		}
	}

	//B2에 입력받는다.
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB2[i][j];
		}
	}
	start = clock();//측정시작

	vector<int> answers = subtract(arrB1, arrB2); //ssd계산하는 함수 호출

	int SSD = *min_element(answers.begin(), answers.end()); //최저값을 찾아서 출력
	cout << SSD << endl; 

	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력
	
	return 0;
}