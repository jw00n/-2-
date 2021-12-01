#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

class Point2D {
public:
	int x; //x좌표
	int y; //y좌표
	int index; //입력받는 데이터 인덱스

	Point2D(int index, int x, int y) { //인덱스도 같이 입력받은 경우
		this->index = index;
		this->x = x;
		this->y = y;

	}

	Point2D(int x, int y) { //아닌 경우, 1로 초기화
		this->index = 1;
		this->x = x;
		this->y = y;
	}

	long long getSquaredDistanceTo(Point2D target) {
		//두 좌표간의 제곱거리를 계산 = 두 개의 좌표를 잇는 정사각형의 면적 
		long long dx = abs(this->x - target.x); //target.x, target.y를 입력받아서 차이의 절대값을 구함
		long long dy = abs(this->y - target.y); 
		return dx * dx + dy * dy; //제곱계산 후 더해주어 정사각형의 면적을 구해 리턴
	}


	
	double getDistanceTo(Point2D target) {
		//두 좌표간의 실수 거리를 계산
		long long sqd = this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}


	//클래스로 정의했으므로 연산자 정의필요 있음
	bool operator < (const Point2D& other)const {
		//각 좌표의 우선순위를 비교하기 위한 비교 연산자

		//x좌표가 다르면 x좌표를 기준으로 비교한다.
		if (this->x != other.x) {
			return this->x < other.x;
		}

		//x좌표가 같다면 y좌표를 기준으로 비교한다.
		return this->y < other.y;
	}


};


long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0; // = 면적 //x,y가 1억이하의 정수이므로 넓이는-> long long타입으로 선언
	 
	//모든 점을 set에 저장한다.
	set<Point2D> pSet; //default: less(오름차순), datatype이 class이므로 대소관계(비교연산) 정의 필요
	
	//set 변수 pSet에 삽입 -> 중복은 x처리
	for (int i = 0; i < n; i += 1) {
		pSet.insert(points[i]);
	}

	//임의의 a,b 두 점을 잡는다.
	for (int i = 0; i < n; i += 1) {
		Point2D pa = points[i]; //임의의 점
		for (int j = 0; j < n; j += 1) {
			Point2D pb = points[j];

			if (i == j) continue; //같은 점은 거리가 0이라 의미없으므로 제외시킴

			//두 기준점 pa와 pb를 지정한다.
			//선분 pa-pb가 정사각형의 한 변이라고 하자.

			//두 점의거리(선분의 길이)의 제곱은 정사각형의 넓이가 된다.
			long long area = pa.getSquaredDistanceTo(pb); //멤버 내부함수 getSquared~를 이용해 면적을 구함

			//이미 구한 사각형보다 넓이가 작다면 이하 과정 수행 필요없으므로 건너뛴다.
			if (area < answer) 
				continue;

			// *정사각형인지 판단할 필요가 있음 *
			//pa -> pb 방향의 x,y 좌표에 대한 거리(차)를 구한다.
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			//벡터 <dx, dy>를 90도로 회전시키면 < -dy, dx >가 된다.
			//pa pb를 벡터 < -dy, dx > 를 각각 더해 정사각형을 구성하는 두 점
			//pd, pc를 계산할 수 있다.
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);
			//이 계산으로 사각형의 꼭지점 A,B,C,D를 다 구하게 됨.

			//pa,pb는 있을테니 pb,pc와 결정적이므로 이 점이 pSet에 존재하는 점인지 검사하면 된다. ->없으면 정사각형이 될 수 없음.
			if (pSet.count(pc) > 0 && pSet.count(pd) > 0) { // O(log2N) ->set으로 빠르게 진행가능해짐
				//if(pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()){
				//if문 조건이 둘 다 1인 경우에만 answer(면적) 업데이트 진행
				answer = max(answer, area); //max값을 업데이트

			}
		}
	}

	return answer;
}

void process(int caseIndex) {
	int n; //좌표의 개수 N
	cin >> n; //입력받는다.

	vector<Point2D> points; //클래스 Point2D로 정의한 벡터변수 선언

	//좌표의 개수만큼 반복하며
	for (int i = 0;  i < n; i += 1) {
		int x,y; //x,y좌표를 입력받음
		cin >> x >> y;
		points.push_back(Point2D(i, x, y)); //벡터 변수에 클래스를 맨뒤부터 삽입해나감.
	}

	double answer = getMaximumSquareArea(n, points); //n과 벡터변수를 인수로 넘겨주어 가장큰 넓이를 구하는 함수 호출

	//소수점 세번째 자리에서 반올림해서 출력
	cout << fixed << setprecision(2) << answer << endl;
}

int main() {
	int caseSize; //테스트 케이스 개수
	cin >> caseSize; //개수 입력받고

	//테스트 케이스 숫자만큼 process 수행
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}