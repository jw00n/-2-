#include<iostream> //입출력
#include<vector> //벡터 변수
#include<queue> //큐 변수

using namespace std;

class Player {
public:
	int index; //멤버

	Player(int index) { //인수를 받아 인덱스로 설정
		this->index = index;
	}
};


/*
 조세퍼스 게임을 수행하여 각플레이어가 제거된 순서를 리스트로 반환하는 함수

 param 
 n  플레이어의 수
 m 매 턴마다 건너 뛸 사람의 수
 players 좌석에 앉아있는 순서대로 주어지는 플레이어 정보

 return
*/

vector < Player> getDeadPlayerList(int n, int m, const vector<Player>& players) {
	//현재 게임에서 제외된 플레이어들의 리스트
	vector<Player> deadPlayers;

	//아직 게임에서 제외되지 않는 플레이어들의 리스트
	queue<Player> que;

	//인수로 받은 벡터 players 정보를 que에 삽입한다.
	for (int i = 0; i < n; i += 1) {
		que.push(players[i]); //1 2 3 4 5 6 7
	}


	/*
	건너뛸때 que를 쓰는 이유 -> 스택은 뒤에서 , 큐는 앞에서 제외를 시킨다.
	데이터를 집어넣을때 삽입은 맨 뒤에서 일어나게 되지만 
	삭제는 맨 앞에서 일어나기 때문에
	큐를 사용
	*/

	//원형 사이클을 도는 구조로, 나머지 연산을 이용해서 어느 위치 숫자를 제외할지 찾아서 구현할 수 있다.

	//n번 반복하면서 계속 제외시킴
	for (int i = 0; i < n; i++) {
		//m-1명의 사람을 건너뛴다.
		//ex) m=3 이면 3->6->2... que.size()=7 //1을 먼저빼고 7로 나눈 나머지는 2 그다음 다시 1을 더해준다.
		int jump = 1 + (m - 1) % que.size();
		for (int j = 0; j < jump - 1; j += 1) {
			Player p = que.front(); //큐 첫 번째 값을 삭제하기전에 임시로 저장한 후
			que.pop(); //삭제
			que.push(p); //p에 임시저장한 값을 넣어준다.
						 //ex) 1번째 반복 2 3 4 5 6 7 1 ->2번째)  3 4 5 6 7 1 2 
		}//완료되면 제외할 값이 맨 첫번째에 오게 된다.


		//m번째 사람은 게임에서 제외한다.
		Player dead = que.front(); //제외할 사람을 dead에 넣어주고
		que.pop();//삭제

		deadPlayers.push_back(dead); //제외 리스트에 추가한다.
	}

	return deadPlayers; 
}

void process(int caseIndex) {
	int n, m; //n명의 사람 수 n // M번째의 m
	cin >> n >> m; //입력받는다.

	vector<Player> players;// 벡터변수 선언 //데이터 타입 -> player에
	for (int i = 0; i < n; i++) { //player에 인덱스를 설정하여 벡터에 삽입하는 반복문
		players.push_back(Player(i + 1)); //숫자는 1부터 시작이므로 +1을 해준다.
	}

	//제외된 사람 리스트를 함수로 알아내서 벡터변수 deadPlayers에 대입
	vector<Player> deadPlayers = getDeadPlayerList(n, m, players); 

	//출력하는 반복문
	for (int i = 0; i < n; i++) {
		if (i > 0) { //공백
			cout << " ";
		}

		//제외된 사람들 리스트의 인덱스를 출력
		Player p = deadPlayers[i];
		cout << p.index;
	}

	cout << endl; //여백 한 줄씩
}

int main() {
	int caseSize; //테스트 케이스 개수
	cin >> caseSize; //입력받음

	//테스트 케이스 숫자만큼 caseIndex가 증가,반복하면서 process 호출
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}

	return 0;
}