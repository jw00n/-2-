#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	int N; //투표 용지 수 N
	cin >> N; //입력받는다.

	//각 후보 이름과 득표 수를 저장하는 key-value Map변수 선언
	map<string, int> frequencyMap;

	int maxFrequency = 0; //가장 많은 득표수 저장하는 변수//처음에는 0으로 초기화

	//각 이름이 하나 추가될때마다 현재까지의 죄다 득표 값 갱신, 최다 득표 후보 리스트를 갱신한다.

	for (int i = 0; i < N; i++){
		string st; //후보자의 이름 st //후보자의 이름은 알파벳 대문자 문자열이다.
		cin >> st; //입력받는다.
		frequencyMap[st]++; //입력받을때마다 해당 key(후보자)의 value값을 ++ //0부터 1씩 증가
		int k = frequencyMap[st]; //value(득표 수)를 k에 임시저장
		if (k > maxFrequency) { //최다 득표수와 비교하여
			maxFrequency = k; //k가 크다면 k의값으로 maxFrequency를 업데이트
		}
	}


	//최다 득표 수를 출력한다.
	cout << maxFrequency << endl;

	//최대 득표한 동점후보들 이름을 사전순으로 출력한다.
	map<string, int>::iterator it;

	//각 후보의 이름과 득표수가 저장된 frequencyMap에서 begin ~ end 까지 최다득표수를 가진 후보이름(key) 출력
	//사전 순으로 출력됨.
	for (it = frequencyMap.begin(); it != frequencyMap.end(); it++) {
		if (it->second == maxFrequency) //value값과 최다득표수와 동일할때
			printf("%s ",it->first.c_str()); //first가 string형이므로 c_str()을 붙여 접근한다.
	}

}