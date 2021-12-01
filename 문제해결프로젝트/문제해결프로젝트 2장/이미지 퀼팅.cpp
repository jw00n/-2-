#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
정리
1. 주어진 값은 겹친 영역의 밝기 값이다.
2. 영역 원소의 값 차이가 가장 작은 것을 고르는 게 1순위
3. 배열인가 벡터인가
4. 트리로 푸는게 좋지 않나? 저번에 썼던것처럼 bfs?

*/


int h, w;
int sum = 0;
vector<int> more;
vector<vector<int>>arr_this(h, vector<int>(w, 0));


//차이를 계산하는 함수
void subtract(vector<vector<int>>arrB1, vector<vector<int>>arrB2) {
	vector<vector<int>>result(h, vector<int>(w, 0));
	int row_count = arrB1.size(); //행 값
	int col_count = arrB1[0].size();  //열 값


	for (int i = 0; i < row_count; i++) {
		for (int j = 0;j < col_count; j++) {
			result[i][j] = abs(arrB1[i][j] - arrB2[i][j]); //절대값 저장하고
		}
	}
	
	arr_this = result;

}

//여기서 최소 값만을 가진 트리 길을 하나 찾아야해
//행과 열을 넘겨주고
//cout << "오류 1" << endl;



void compare(int row, int col) {
	cout << "compare" << endl;
	vector<vector<int>>please(h, vector<int>(w, 0));
	cout << "오류 please아래" << endl;
	please = arr_this;
	vector<int> more;
	cout << "개같다" << endl;
	cout << row << "<행 // 열>" << col << endl;

	if (row > h-1) { //마지막 행까지 시행했다면 끝나게
		return ;
	}
	if (row == 0) { //넣어준다 //out of range
		cout << "오류 여기야???" << endl;
		cout<<"이건 접근이 되니?  ="<< please[row][col]<<endl;
		more[row] = please[row][col]; //여기 오류남
		cout << "아잇시발" << endl;
	}

	if (col == 0) {//맨 처음 열 경우

		if (please[row + 1][col] < please[row + 1][col + 1]) //오른쪽이 크다면
		{//cout << "오류 1" << endl;
			more[row + 1] = please[row + 1][col];
			//cout << "오류 2" << endl;
			compare(row + 1, col); //다음거 실행
		}
		else
		{//cout << "오류 3" << endl;
			more[row + 1] = please[row + 1][col + 1];
			//cout << "오류 4" << endl;
			compare(row + 1, col + 1);
		}
	}
	else if (col == w) { //맨 마지막 열 경우
		if (please[row + 1][col - 1] < please[row + 1][col]) {
			//cout << "오류 5" << endl;
			more[row + 1] = please[row + 1][col - 1];
			//cout << "오류 6" << endl;
			compare(row + 1, col - 1);
		}
		else {
			//cout << "오류 7" << endl;
			more[row + 1] = please[row + 1][col];
			//cout << "오류 8" << endl;
			compare(row + 1, col);
		}
	}
	else { //그외, col(1~w-1) 3개의 값을 비교해야한단 말이지
		//cout << "오류 9" << endl;
		int min_index = min_element(please[row+1].begin()+col-1, please[row+1].end() +col+1)- please[row+1].begin();
		//cout << "오류 10" << endl;
		more[row + 1] = please[row + 1][min_index];//최소값 넣어줌
		//cout << "오류 11" << endl;
		compare(row+1, min_index);//최소값을 가진 원소의 행과 열을 넘겨줌.
	}

	
}






int main() {
	// h= 포개진 두 이미지의 높이 (1~100) / w= 영역의 너비(1~100)
	cin >> h >> w; //입력을 받는다.

	vector<vector<int>>arrB1(h, vector<int>(w, 0)); //h행 w열 이중 벡터1
	vector<vector<int>>arrB2(h, vector<int>(w, 0));// 벡터 2


	//값 집어넣는 것

	//B1
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB1[i][j];
		}
	}

	//B2
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB2[i][j];
		}
	}


	subtract(arrB1, arrB2); // 절대값 계산


	//여기서  compare로 넘어갈때 result로 최소값 먼저 줘야돼
	int firstmin_index = min_element(arr_this[0].begin(), arr_this[0].end()) - arr_this[0].begin();
	cout <<"first"<< firstmin_index << endl;

	compare(0, firstmin_index);
	
	
	for (int i = 0; i < more.size(); i++) {
		sum += more[i] * more[i];
	}

	cout << "합계= " << sum << endl;
	
	


	/*

	cout << "1번째 벡터" << endl;
	for (vector<int> vec : arrB1) {

		for (int num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << "2번째 벡터" << endl;
	for (vector<int> vec : arrB2) {
		for (int num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}



	*/


}