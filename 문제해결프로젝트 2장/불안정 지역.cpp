#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class City {

public:
	int index; //도시의 인덱스
	int income; //해당 도시의 소득

	//인자로 받아서 값 설정
	City(int index, int income) {
		this->index = index;
		this->income = income;
	}

	//income을 이용해 대소 관계 
	bool operator < (const City& o) const {
		return this->income < o.income;
	}

	bool operator > (const City& o) const {
		return this->income > o.income;
	}
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	int answer = 0; //가장 큰 소득차가 저장될 변수 //0으로 초기화 

	//소득이 가장 작은 도시부터 pop되는 우선 순위 큐

	//priority_queue<클래스, 벡터 컨테이너, 비교함수 클래스>
	//클래스로 비교연산을 할 경우 클래스에 정의되어있어야한다.
	//탑에서 볼때 오름차순이므로 탑이 가장 작음 -> 탑 제거 = 최소값 제거
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	//소득이 가장 높은 도시부터 pop되는 우선순위 큐
	priority_queue<City> rangeMaximum;
	//데이터 타입만 쓰는 경우 less가 생략된 경우이다.
	//priority_queue<City, vector<City>, less<City>> rangeMaximum;

	//이렇게 하면 O(n) 시간복잡도로 코딩가능

	//ex) income 10 2 5 3 7 9 1
	for (int i = 0; i < k - 1; i++) { //k=3 -> k-1 =2 
		rangeMaximum.push(cities[i]); // 큰 값이 가장 위로 정렬됨.
		rangeMinimum.push(cities[i]); // 작은 값이 가장 위로.
	}

	//i=2부터 ~n까지 반복
	for (int i = k - 1; i < n; i++) {
		//cities 정보를 넣게됨
		rangeMaximum.push(cities[i]); //top = 가장 큰 값으로 순서대로 정렬됨
		rangeMinimum.push(cities[i]); //top = 가장 작은 값 으로 정렬됨
		//while문에서 top값을 삭제함. -> 모든 범위에서 최대최소값을 구하는게 아닌 인접한 일정 k값 범위안에서 구해야하기 때문
		//위치정보 -> index가 범위안에 있어야함. 범위 밖이면 pop로 삭제
		while (rangeMaximum.top().index < i - k + 1) rangeMaximum.pop(); 
		while (rangeMinimum.top().index < i - k + 1) rangeMinimum.pop();
		//그 이전 반복에서 구한 격차 값을 계속 비교하며 answer를 업데이트
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
	}

	//최종적인 answer = 가장 큰 소득 격차를 리턴
	return answer;



}

//caseindex를 굳이 사용하지 않아서 인자로 줄 필요는 없어보임.
void process(int caseIndex) {
	int n, k; //n = 도시의 수 //k= 한 조사 영역이 포함하는 연속한 도시의 수
	cin >> n >> k;//입력
	vector<City> cities; //벡터 변수 선언 //데이터 타입은 City 클래스로 선언

	for (int i = 0; i < n; i += 1) {
		int income;//소득정보
		cin >> income;//입력받아서
		cities.push_back(City(i, income)); //인덱스와 소득 정보를 city클래스를 벡터에 삽입
	}

	//소득 격차를 계산하는 함수를 통해 가장 큰 소득차를 알아내어 answer에 삽입
	int answer = getMaximumRangeDifference(n, k, cities);

	//출력
	cout << answer << endl;
}


int main() {
	int caseSize; //테스트  케이스 수를 입력받는다.
	cin >> caseSize;

	//케이스 숫자만큼 반복하며 프로세스 수행
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}


}

//이중 for문으로 구현하게 되면 시간복잡도가 O(n^2)으로 비효율적일 것이다.
//우선순위 큐를 통해 효율적인 것을 추구하는 것을 목표로+