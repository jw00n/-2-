#include <algorithm>
#include <iostream>
#include<vector>
#include<time.h>

using namespace std;


int getWhichfood(int k, const vector<int>& foodTime) {
	int sum = 0; //음식을 먹는 총 소요 시간 저장변수
	int time = 0; 
	int pretime = 0; //직전에 먹은 음식 시간
	int size = foodTime.size(); // =음식 개수

	vector<pair<int, int>> range; //음식먹는 시간, 인덱스 저장하는 벡터

	for (int i = 0; i < foodTime.size(); i++) {
		sum += foodTime[i];	//모든 음식 소요시간을 더한 sum
		range.push_back(make_pair(foodTime[i], i + 1)); //음식 시간과 인덱스를 묶어 하나의 객체취급
	}
	sort(range.begin(), range.end()); //오름차순 정렬

	if (sum <= k) return -1; //방송중단시간과 모든 음식섭취시간이 일치하면 다 먹은경우이므로 -1 반환


	for (vector<pair<int, int>>::iterator i = range.begin(); i != range.end(); i++) {
		time = (i->first - pretime) * size; //오름차순으로 나열했을때 첫번째 원소에서 이전시간을 뺀 후 * 음식개수 ->가장 시간이 적게 걸리는 음식을 소요하는 시간
		
		if (time <= k) {//위의 time이 k(중단시간)보다 같거나 작다면
			k -= time; //k에서 감소시킨다.
			pretime = i->first; //pretime은 직전 음식 시간이므로 업데이트
		}
		else {//k가 time보다 작아졌을때 즉 더는 한 사이클을 돌지 못하고 중도에서 멈출때
			sort(i, range.end());  //오름차순으로 정렬
			return (i + (k % size))->second; // 인덱스를 찾아 리턴해준다.
		}
		size--; //음식개수를 감소시켜서 반복
	}


}



void process(int n) {

	vector<int> foodTime;//음식 시간을 저장하는 벡터

	//각 음식의 먹는 시간을 입력받아 벡터에 저장한다.
	for (int i = 0; i < n; i++) {
		int eachTime;
		cin >> eachTime;
		foodTime.push_back(eachTime);
	}

	int k; //중단된 시간을 입력
	cin >> k; //입력받는다.
	clock_t start, end; //시간 측정
	start = clock();//측정시작

	int answer = getWhichfood(k, foodTime); //인수로 음식먹는 시간을 저장한 벡터와 즁단 시간 k를 넘겨준다.

	cout << answer << endl; // 몇 번 음식부터 먹어야 할지 출력 
	end = clock(); //측정 종료 
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 초단위로 출력

}

int main() {

	int n; //음식의 개수 n을 입력받는다.
	cin >> n;

	//프로세스 수행
	process(n);
 
	return 0;
}