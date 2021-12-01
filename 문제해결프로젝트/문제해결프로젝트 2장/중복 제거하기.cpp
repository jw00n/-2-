#include<iostream>
#include<set> //중복여부를 가장 판단하기 좋은 set -> 데이터가 나열되어있을때 탐색이 빠름

using namespace std;

int main() {
	int n; //데이터의 개수
	cin >> n; //입력받음

	//integers = 이전까지 등장한 모든 정수를 저장한 집합
	set<int> integers; //int형 set 변수 -> 기본) 오름차순으로 정렬됨
 
	for (int i = 0; i < n; ++i) { //n번 반복하면서 
		int x;//x=정수 입력받음.
		cin >> x;

		/*
		C++ set의 find 메소드는 
		찾는 숫자가
		있다면 해당 iterator를,
		없다면 end() iterator를 반환한다.
		*/

		//set변수.count(element) -> element가 set변수안에 있다면 1/없으면 0
		if (integers.count(x) > 0) { //이미 찾는 수가 있다면 integers.find(x) != s.end()
			cout << ">> DUPLICATED" << endl; //중복 표시
			//cout  <<*integers.find(x) << endl; 
		}
		else{ //찾는 수가 없다면(중복이 아니니)
			integers.insert(x); //set에 수(x)를 등록한다.
			cout << ">> OK" << endl; //등록되었다는 뜻으로 ok 출력
		}
	}

	return 0;
}

