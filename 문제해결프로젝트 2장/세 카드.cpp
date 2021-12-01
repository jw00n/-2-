#include <stdio.h>
#include <vector> //push_back, size
#include<algorithm> //sort, binary_search

using namespace std;

/*
중복을 포함해 두 카드의 합으로 만들 수 있는 당첨번호의 수를 계산하는 함수
param
n - 카드의수
m - 검사하려는 당첨번호의 수
cards - 각 카드에 적히 ㄴ숫자들
target - 검사하려는 각 당첨번호 리스트
@return

*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets)
{
	vector<int> possibleTargets; //만들 수 있는 당첨번호들

	//바이너리 서치를 위한 조건 -> 모든 카드를 오름차순으로 "정렬"한다. 
	sort(cards, cards + n); //sort(시작위치, 끝 위치) //cards, cards+n으로 n개의 모든 원소를 정렬시킴

	for (int i = 0; i < m; ++i) // m= 당첨번호의 수만큼 반복
	{
		int k = targets[i];//모든 타겟 k에 대하여
		bool possible = false; //처음엔 false로

		for (int j = 0; j < n; ++j){ //내부 3개의 값을 더할 반복문
			int x = cards[j]; //모든 카드 중 하나인 x에 대하여

			for (int p = 0; p <= j; p += 1)//숫자 조합의 중복 없애기 연산량을 줄이기 위해 j까지 반복
			{
				int y = cards[p];//카드 중 하나 y를 선택한다.
				int z = k - (x + y); //k=(x+y) +z 가 되는 z를 계산한다.

				//z가 cards[]에 존재한다면?
				if (binary_search(cards, cards + n, z) == true) //binary_search(시작위치, 끝위치, 찾을 값)으로 z를 찾는다.
				{
					possible = true;	//k = x+y+z 가 가능한 <x, y, z>가 존재한다. -> true
					break; //->3번째 for문에서 벗어남
				}
			}

			if (possible) { //이미 찾았다면 탈출한다.
				break; //->두 번째 for문에서 탈출
			}
		}

		if (possible) { //세 카드의 합으로 k를 만들 수 있다면, 추가한다.
			possibleTargets.push_back(k); 
		}
	}

	sort(possibleTargets.begin(), possibleTargets.end()); //k가 추가된 이후므로 오름차순으로 정렬
	return possibleTargets; //출력값이 저장되어있는 벡터 리턴
}


int main() {
	int n; // 카드의 수
	int m; // 검사 할 후보 당첨번호의 수

	scanf("%d %d", &n, &m);// 데이터를 입력받음

	int *cards = new int[n]; //n개 만큼 크기의 카드번호 배열
	int *targets = new int[m];//m개 만큼 크기의 당첨번호 배열

	//각 카드 정보를 입력받는다.
	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}

	//각 후보 당첨번호를 입력받는다.
	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}

	//getPossibleTargets를 통해 세 개의 숫자의 합으로 표현될 수 있는 당첨번호를 구한다.
	vector<int>  answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0) //가능한 당첨번호가 없다?
	{
		printf("NO"); //NO 출력
	}

	else //가능한 당첨번호가 존재한다면 그 목록을 출력한다.
	{
		for (int i = 0; i < answers.size(); i++)
		{
			if (i > 0)// 사이 공백 출력
			{
				printf(" ");
			}
			printf("%d", answers[i]); //조건에 부합한 정렬된 값이 출력된다.
		}
	}

	//끝났다면 비워줍니다.
	delete[] cards;
	delete[] targets;

	return 0;
}