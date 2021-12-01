#include<iostream>
#include<cmath>
#include<stack>
#include<vector>

using namespace std;

class Histogram {
public:
	int height; //히스토그램의 높이
	int leftX; //인덱스 혹은 히스토그램의 왼쪽 변의 x 좌표
	int rightX; //히스토그램의 오른쪽 변의 x좌표

	Histogram(){ }

	Histogram(int index, int height) {
		this->leftX = index; //인덱스를 x좌표
		this->rightX = this->leftX + 1; //각 히스토그램은 너비가 1이므로 +1
		this->height = height; //높이
	}

};

long long getLargeRectangleArea(const vector<Histogram>& histograms) {
	long long answer = 0; //최대 직사각형의 넓이

	//현재 우측으로 확장 가능성이 높은 히스토그램
	stack<Histogram> stk; //스택 변수

	//구현상 편의를 위해 가장 왼쪽에 높이 0까지 가상의 히스토그램 추가
	stk.push(Histogram(-1, 0));

	for (int i = 0; i < histograms.size() + 1; i++) {
		//왼쪽부터 오른쪽 히스트그램까지 차례로
		Histogram h;
		if (i < histograms.size()) { //i가 size값보다 작다면
			h = histograms[i]; //h에 인덱스 i의 히스토그램 넣어준다.
			
		}
		else {
			//if(i==n)
			//구현상 편의를 위해 가장  오른쪽에 높이 0까지 가상의 히스토그램 추가
			h = Histogram(histograms.size(), 0);
		}

		//이전에 확장 중이던 히스토그램들 중, h 보다 높이가 높은 히스토그램들은
		//더이상 확장될 수 없다 -> 최대 넓이 결정된다.
		while (stk.size() > 1
			&& stk.top().height > h.height) { //size가 1보다 크며 왼쪽 히스토그램이 더 높을때 반복됨.
			//확장중이던 히스토그램//높이가 오름차순인지 //아니라면 확장이 불가능하므로 종료시킴
			Histogram lh = stk.top(); //삭제하기 전의 top를 나중에 사용하기 위해
			stk.pop(); //이후 삭제

			//그 이전의 히스토그램 (왼쪽 확장의 끝)
			Histogram bh = stk.top(); //초기값은 0 , 이후 그 이전 히스토그램의 높이
			

			//현재 추가된 h의 바로 왼쪽까지 확장중
			long long width = abs(h.leftX - bh.rightX); //차를 이용해 너비를 구함
			long long height = lh.height; //높이
			long long area = width * height; //넓이

			//계속 비교하며 최대값 갱신
			answer = max(answer, area);
		}

		//h를 새로이 추가한다.
		stk.push(h);
	}
	return answer;//결과 리턴
}

void process(int caseIndex) {
	int n; //그래프 개수
	cin >> n;//입력

	vector<Histogram> histograms; //벡터 변수 선언
	for (int i = 0; i < n; i++) {
		int height; 
		cin >> height; //반복문을 통해 height값을 입력받아
		histograms.push_back(Histogram(i, height)); //인덱스와 height를 설정
	}

	//answer는 10만의 제곱값을 최대로 할 수 있으므로 long long 타입
	long long answer = getLargeRectangleArea(histograms); //histograms로 최대 넓이를 계산하여 answer에 넣어준다.
	cout << answer << endl; //answer 출력

}

int main() {
	int caseSize; //테스트 케이스 수
	cin >> caseSize; //케이스 개수를 입력받는다. 

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex); //케이스 개수만큼 process 호출
	}
}


/* 3중 반복문 - 시간복잡도 O(n^3)
for(int l = 0 ~ n-1)
{
	for(int r=l ~ n-1)
	{
		for(int i= l~r)
		{
		//높이 최소값 구하기
		//면적 = (r-l+1)*높이 최소값
		}
	}
}

*/