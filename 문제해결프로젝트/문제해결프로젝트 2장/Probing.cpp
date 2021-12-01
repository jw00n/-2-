#include<cstdio>
#include<vector>

using namespace std;

class TicketTable {
public:
	vector<bool> used; 
	int length;

	TicketTable(int length) { //length<-n
		this->length = length;
		this->used.assign(length, false); //false로 초기화
	}

	
	//사용자의 회원번호로 지급받게 될 행운권 번호를 계산하는 메소드
	int findEmptyIndexByUserId(int userId) { //인덱스값을 넘겨받고
		int index = userId % length; //가장 초기에 시도할 티켓 번호
		while (this->isEmpty(index) == true) { //사용된 티켓 번호(true)라면 건너뛴다.
			index = (index + 1) % length; //다음 번호를 조사해나간다.   eX_ 2879라면 1씩 증가하면서 false를 찾을때까지 반복
		}
		return index; //반복문을 벗어나 사용되지 않은 인덱스를 찾아서 변환한다.
	}

	/*
	해당 행운권 번호가 이미 사용중인지 여부를 반환하는 메소드
	*/

	bool isEmpty(int ticketIndex) {
		return this->used[ticketIndex];// 사용여부<==> used[ticketIndex]
	}
	 //티켓 사용 여부를 갱신하기 위한 메소드
	void setUsed(int index, bool status) {
		this->used[index] = status;  //true로 업데이트
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
	vector<int> tickets; //벡터 변수
	TicketTable table = TicketTable(n); //구조체 선언

	for (int i = 0; i < m; i++) { 
		int userId = ids[i]; //인덱스 값을 저장
		int ticketIndex = table.findEmptyIndexByUserId(userId); //인덱스 값을 넘겨줌
		tickets.push_back(ticketIndex); //인덱스값을 추가
		table.setUsed(ticketIndex, true); //사용된 것이므로 true로 선언
	}

	return tickets; // 리턴
}

int main() {
	//n : 전체 타겟의 수
	//m : 요청 고객의 수

	int n, m;
	scanf("%d %d", &n, &m); //입력받음
	 
	vector<int> ids(m); //인덱스라는 벡터변수 선언
	for (int i = 0; i < m; ++i) { //값을 순서대로 입력받음
		scanf("%d", &ids[i]);
	}

	vector<int> tickets = getTicketNumbers(n, m, ids); //회원번호를 부여하는 함수 호출
	for (int i = 0; i < tickets.size(); ++i) {
		printf("%d\n", tickets[i]); //tickets의 변수 출력
	}

	return 0;
}


