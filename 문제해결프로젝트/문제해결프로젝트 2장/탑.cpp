#include<iostream>
#include<stack>
#include<vector>

using namespace std;



class Tower {
public:
	int index; //타워의 인덱스(위치정보)
	int height; //타워의 높이
	int targetTowerIndex; //이 타워의 레이저를 수신하는 대상 타워

	Tower(int index, int height){
		this->index = index; //각각 인자로 설정하고
		this->height = height;
		this->targetTowerIndex = 0; //targetTower index는  0으로 초기화
	}


	//setTarget~ 과 getTarget~으로 targetTowerIndex값을 설정하거나 반환한다.
	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex() {
		return this->targetTowerIndex;
	}
};

/*
예시대로 실행했을때,

1. 처음엔 t.setTargetTowerIndex(targetTowerIndex); 부터 실행됨. -> 0값을 대입하게 된다.
> 다음 stk.push(t)를 통해 6이 삽입되게됨. 출력은 0

2. 9가 들어오고 empty ==false 가 되고 6과 9를 비교하게 됨. 6이 낮으므로 제거
>  0 출력, push를 통해 9가 스택으로 들어옴

3. 다음 5, 9와 비교하고 조건에 부합하지 않으므로 9는 남아있음. 인덱스는 2가 출력 / 5 스택에 저장

4. 다음 7 , 5하고 비교 -> 5가 더 작으므로 제거 -> 7과 9비교에서 9는 여전히 남아있고 위치정보 2가 다시 출력 /7 스택에 저장

5. 다음 4, 4와 7비교에서 7은 남게되고 7의 인덱스 4가 출력
*/

void findTargetTowers(vector<Tower>& towers) {
	//현재 다른 타워의 신호를 수신할 가능성이 있는 타워
	stack<Tower> stk; //스택변수 선언

	//시간복잡도 O(N)
	for (int i = 0; i < towers.size(); i++) {
		Tower& t = towers[i]; //각 타워 t에 대해 차례로 고려
		int targetTowerIndex = 0; //타워 t의 신호를 수신할 후보 (초기값 null)

		while (stk.empty() == false 
			&& stk.top().height < t.height) {
			//t보다 높이가 낮은 타워들은 이후에도 수신 가능성이 없으므로 제거
			stk.pop();
		}

		//t이상의 높이를 가진 타워가 남아있다면?
		if (stk.size() > 0) {
			//t는 해당 타워를 타겟으로 정하게 된다.
			targetTowerIndex = stk.top().index;
		}
		//계산할 타겟 정보를 저장한다.
		t.setTargetTowerIndex(targetTowerIndex);

		//t는 마지막에 등장했으므로 다른 타워의 신호를 수신할 수 있다. 등록
		stk.push(t); 
	}
}

int main() {
	int n; //탑의 개수 N
	cin >> n; //n을 입력받는다.


	vector<Tower> towers; //벡터 변수 선언
	for (int i = 0; i < n; ++i) { //탑의 개수만큼 반복하며 탑들의 높이를 입력받는다.
		int hi;
		cin >> hi; //탑 높이 h1
		towers.push_back(Tower(i + 1, hi)); //벡터 변수에 인덱스 1부터 저장
	}

	//각 타워가 송신하는 레이저에 대해 타겟을 모두 계산한다.
	findTargetTowers(towers);

	//출력하는 반복문
	for (int i = 0; i < n; i++) {
		if (i > 0) { //i=1부터 공백 출력
			cout << " ";
		}

		Tower t = towers[i]; 
		int targetIndex = t.getTargetTowerIndex(); //순서대로 인덱스 반환되어
		cout << targetIndex; //출력
	}
}

//데이터 삽입삭제가 끝부분에서만 일어난다면 스택을 고려<<

/* 스택없이 하는 법 / 시간복잡도 O(N^2)
for(i=0~N-1)
{
	int target =0;
	for(j=i-1~0)
	{
		if(h[j]>h[i])
		{
			target =j;
			break;
		}
	}
}

*/