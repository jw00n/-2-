#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000; //1~100000

/*
data[0]~ data[n-1]에 등장한 시리얼 번호들에 대한 빈도수 테이블을 채우는 함수

param data
param n
table table[x] := data 배열에서 x가 등장한 횟수
*/

//
void fillFrequencyTable(const vector<int>& data, int n, vector<int>& table) {
	table.clear();//모든 원소 제거
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //크기를 변경 및 0으로 초기화 , 100000 표현를 위해 +1

	for (int i = 0; i < n; ++i) { 
		int serial = data[i]; //데이터 값을 인덱스로
		table[serial] += 1; //table을 1씩 증가
	}
}

/*
data[0] ~ data[n-1]에서 중복이 존재하지 않는 원소들을 반환한다.
단, 각 원소들은 오름차순으로 정렬되어 있어야한다.
data data[0] ~ data[n-1]에는 10만 이하의 자연수다.
n
return 
*/

vector<int> getUniqueElements(const vector<int>& data, int n) {

	vector<int> ret; //유일한 원소들을 갖는 배열로 비어있는 벡터 생성, 배열과 달리 고정 사이즈가 아님

	
	vector<int> table;//table 생성
	fillFrequencyTable(data, n, table); //data에 대한 빈도수 테이블을 계산

	//중복을 제거하기 위한 for문
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) {
		//존재할 수 있는 모든 시리얼 넘버에 대해 차례로 조회한다.

		//전체 데이터에서 한번만 등장한 number를 차례로 정답 리스트 ret에 추가한다.
		if (table[number] == 1) { //등장횟수 =1 ?
			ret.push_back(number); //업데이트
		}
	}

	//오름차순으로 추가했으므로 ret 정렬은 불필요
	return ret;
}

int main() {
	int n; //응모한 번호의 개수 변수 선언 
	scanf("%d", &n);//입력받음

	vector<int> data = vector<int>(n); //벡터 컨테이너로 크기 n으로 선언

	for (int i = 0; i < n; ++i) { //배열과 같은방법으로 데이터 입력받음
		scanf("%d", &data[i]);

	}

	const vector<int> answer = getUniqueElements(data, n); //중복을 없애고 각각 하나의 숫자만이 남게하는 함수 호출

	//각 원소들을 출력한다.
	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0) { //i=0일때만 앞에 공백을 하나 추가한다.
			printf(" ");
		}
		printf("%d", answer[i]); //원소 출력
	}

	return 0;
}




/*
벡터 컨테이너: 자동으로 메모리가 할당되는 배열
<vector> 헤더 파일 추가
using namespace std; ->표준 네임스페이스를 사용하여 std::vector
vector의 선언은 vector<data type> 변수명
vector<int> v -> 비어있는 배열 선언
vector<int> v(5); -> 0으로 초기화된 5개의 원소를 갖는 배열 생성
vector<int> v(5,2); -> 5개의 원소를 갖는 배열, 모든 값을 2로 초기화
vector는 여러가지 멤버함수를 가짐.

v.size(); -> 원소의 개수 리턴
v.clear(); -> 모든 원소 제거, 원소만 제거하고 메모리는 그대로
v.resize(n,3); -> 크기를 n으로 변경하고, 인자의 값을 3으로 초기화
v.push_back(7); -> 마지막 원소 뒤에 원소 7을 삽입
배열의 단점: 원소 추가,삭제, 크기변경이 어렵다
*/
