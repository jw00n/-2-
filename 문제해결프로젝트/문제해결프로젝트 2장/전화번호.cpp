#include <cstdio>

using namespace std;

const int MAX_TABLE_LENGTH = 10000;// 0~ 9999 최대 길이 고정

/*
data[0]~data[n-1] 에 등장한 번호들에 대한 빈도수 테이블을 채우는 함수

param data
param n
table table[x] :=data 배열에서 x가 등장한 횟수

*/

void fillFrequencyTable(int data[], int n, int table[])
{
	int frequent_number = 0;//빈도수 변수 선언

	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //table 값을 모두 0으로 초기화
	{
		table[i] = 0;
	}

	for (int i = 0; i < n; i++) //데이터 개수만큼 반복
	{
		frequent_number = data[i]; //데이터 값을 입력
		table[frequent_number] += 1; //frequent_number를 인덱스로 하는 table 히스토그램을 1씩 증가
	}



}

/*
cnt 배열이 해당의미를 만족하도록 각 값을 채워보자
data[0] ~ data[n-1] 사이에서 가장 많이 등장한 번호를 반환하는 함수
data 
n
return 가장 많이 등장한 번호, 여러개인 경우 사전순으로 가장 빠른 번호
*/

int getFrequentNumber(int data[], int n) {
	//0000~ 9999 중에서 가장많이 등장한 번호를 구해보자
	int frequent_number = 0; //0으로 초기화
	int table[MAX_TABLE_LENGTH]; //0~9999까지 숫자의 횟수를 카운트하는 히스토그램

	fillFrequencyTable(data, n, table); //호출

	for (int i = 0; i < MAX_TABLE_LENGTH; i++)
	{
		if (table[i] > table[frequent_number]) //비교해서 table[i]의 값이 크다면 횟수가 현 frequent_number가 가리키는 횟수보다 많으므로
			frequent_number = i;// 업데이트
		/*
		만약 횟수가 같은 번호가 두 개인 경우, 
		작은 것부터 순차적으로 반복문을 돌아서, 횟수가 같은 번호는 뒤에 있을 것이다. 
		횟수가 같은 큰 숫자는 조건문을 통해 횟수가 같더라도 작은 숫자가 frequent_number로 들어간다.
		*/	
	}
	 
	return frequent_number; //빈도 수 리턴

} 

int main() {
	int n; //전화번호 개수 

	scanf("%d", &n); //n 입력받아 
	int* data = new int[n]; //배열 할당

	for (int i = 0; i < n; i++) { //배열에 데이터 입력받는 for문
		scanf("%d", &data[i]);
	}

	int answer = getFrequentNumber(data, n); //빈번히 등장하는 번호 출력하는 함수 호출

	//네 자리로 출력하기위해 => "%04d" ex) 0 -> 0000, 999-> 0999
	printf("%04d", answer);

	delete[] data;

	return 0;
}