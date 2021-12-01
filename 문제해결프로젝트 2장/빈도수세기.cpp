#include<stdio.h>
#include<map>

using namespace std;

int main() {
	int N; //입력으로 주어질 정수의 개수 N
	scanf("%d", &N); //입력받는다.

	//각 <정수, 빈도수> 형태로 key/value=횟수를 저장할 Map 자료구조 정수형)
	//frequencyMap := 이전에 입력된 정수들의 빈도수를 저장하고 있다.
	map<int, int> frequencyMap;
	 
	for (int i = 0; i < N; i++) {
		int X; //N번 반복하며 
		scanf("%d", &X); // 정수를 한 줄 씩 입력받는다.
		frequencyMap[X]++;//frequencyMap[key]-> key값으로 찾아 key에 대응하는 value값리턴
		//key값에 입력받은 정수 X를 넣고 value(빈도수)는 0으로 초기화됐다가  ++로 1씩 증가한다
		printf("%d %d\n", frequencyMap.size(), frequencyMap[X]); //frequencyMap.size() = 종류 수 //frequencyMap[X]=빈도 수가
	}
	//중복된 값도 ++로 횟수가 증가된다.

	return 0;

	/*
	key값 또한 출력하고 싶은 경우))) 이 경우 key값을 바탕으로 오름차순으로 나온다. 

	map<int, int> :: iterator it;

	for(it = frequencyMap.begin(); it!= frequencyMap.end(); it++)
	{
	printf("%d %d\n", it->first, it->second); //first->key // second->횟수  
	}
	*/
}