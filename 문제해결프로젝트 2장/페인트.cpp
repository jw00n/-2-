#include <cstdio>
#include<vector>

using namespace std;

const int MAX_SENT_NUMBER = 1000; //1000이하의 자연수
const int MAX_COLOR_NUMBER = 100; //0~99번의 색깔

//좌석들을 한번 색칠하는 이벤트에 대한 정보
class Painting {
public:
	int left; //색칠할 가장 왼쪽 좌석의 번호
	int right; //오른쪽
	int color; //칠할 색깔의 번호

	Painting(){}

	Painting(int left, int right, int color) {
		this->left = left;
		this->right = right;
		this->color = color;
	}



};


/* 
* data[0] ~data[n-1]에 등장한 번호들에 대한 빈도수 테이블을 채우는함수
 
param data
param n
table table[x] := data 배열에서 x가 등장한 횟수 
*/

void fillFrequencyTable(int data[], int n, int table[]) {
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) { //0으로 초기화
		table[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int color = data[i]; //데이터 값을 color에 지정하고
		table[color] += 1; //그를 인덱스로 하는 table을 1씩 증가
	}

}

void solve(int n, int m, const Painting* paintings) {
	int* seats = new int[n]; //크기 n의 좌석 배열 
	for (int i = 0; i < n; i++)
	{//처음 좌석은 전부 0번 색으로 칠해져있다. 0으로 초기화
		seats[i] = 0;
	}
	
	//색칠 정보들이 주어진 순서대로 각 좌석을 색칠한다.
	for (int i = 0; i < m; i++) {

		//모든 색칠 정보 p에 대하여 차례대로
		const Painting &p = paintings[i];

		//각 페인팅  정보마다 좌석의 색을 업데이트 해준다.
		for (int j = p.left; j <= p.right; j++) {
			seats[j] = p.color; //컬러값을 좌석배열에 업데이트
		}
	}

	//모든 색칠을 완료한 이후의 색상정보를 사용하여
	//모든 색상에 대한 빈도수 테이블을 계산한다.
	int* table = new int[MAX_COLOR_NUMBER];
	fillFrequencyTable(seats, n, table); //히스토그램 구하는 함수 호출

	//초기화
	int minColor = seats[0]; //가장 적게 등장한 색상
	int maxColor = seats[0]; //가장 많이 등장한 색상

	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
		if (table[color] == 0) { //한번도 등장하지 않은 색깔의 경우 제외시키므로 넘어감
			continue;
		}

		//한 번 이상 등장한 모든 색깔 color에 대하여

		if(table[minColor]> table[color]){
			//가장 적게 등장한 색이 아직 없거나 color가 더 적게 등장한 경우
			minColor = color; //업데이트
		}
		if (table[maxColor] < table[color]) {
			//가장 많이 등장한 색이 아직 없거나 color가 더 많이 등장한 경우
			maxColor = color; //업데이트
		}
	}
	
	//출력
	printf("%d\n", maxColor);
	printf("%d\n", minColor);

	delete[] table;
}

int main() {
	int n, m; //좌석 개수 n, 컬러 개수 m
	scanf("%d %d", &n, &m); //입력

	//paintings[i] := i 번째 일어난 색칠 이벤트의 정보
	Painting* paintings = new Painting[n]; //크기는 n으로
	


	for (int i = 0; i < m; ++i) { // left, right , color 변수 입력받음
		
		scanf("%d", &paintings[i].left); 
		scanf("%d", &paintings[i].right);
		scanf("%d", &paintings[i].color);

		//좌석의 번호는 1번부터 시작하므로, 0~ (n-1)범위로 맞추기 위하여 1씩 빼준다.
		paintings[i].left -= 1;
		paintings[i].right -= 1;
	}

	//정답 구하기
	solve(n, m, paintings);

	return 0;
}


