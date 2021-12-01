#include <cstdio>
#include<vector>

using namespace std;

const int MAX_N = 1000000; //최대 N의 값
vector<int> FIBONACCI_TABLE; //벡터컨테이너로 전역변수 선언

/*
피보나치 수열의 1~ n번째 항을 배열에 저장하여 반환해주는 함수 
단, 항의 가장 뒤 8자리만을 저장
param n
return fibo[i] := 피보나치 수열의 i번째 항

*/

vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; 

	//피보나치 배열을 미리 선언 n+1인 이유는 1번부터 시작하기때문에
	vector<int> ret(n + 1);
	ret[1] = 0; //1항은 0 
	ret[2] = 1; //2항은 1


	//3항부터는 피보나치의 정의를 이용해 계산
	//f(n) =f(n-1)+f(n-2)
	for (int i = 3; i <= n; ++i) {
		ret[i] = ret[i - 1] + ret[i - 2];

		/*
		피보나치를 구할때 모듈러 값을 이용해 마지막 8자리만을 남기도록 해준다.
		((A% MOD) + (B % MOD)) % MOD == (A+B) % MOD
		위 식이 성립하기 때문에 피보나치의 값이 잘못될 일은 없다.
		*/
		ret[i] %= MOD; //마지막 8자리만을 저장
	}
	return ret; //마지막 8자리 리턴
}

/*
피보나치 수열의 n 항을 반환하는 함수
단, 항의 가장 뒤 8자리만을 반환
param n
return
*/
int getFibo(int n) {
	//피보나치의 값을 미리 계산해뒀으므로 그 값을 반환한다.
	//1항의 인덱스는 0이므로 -1을 해준다.
	int answer = FIBONACCI_TABLE[n];//저장되어있는 n항의 마지막 8자리 값을 입력
	return answer; //리턴
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N); 
	//전처리를 통해 미리 계산

	int caseSize; //테스트 케이스 수 
	scanf("%d", &caseSize);//입력받음
	
	for (int caseIndex = 1; caseIndex<=caseSize; ++caseIndex) { //케이스 수만큼 반복하며
		int n; //어떤 수 n을 입력받음
		scanf("%d", &n);

		//피보나치 수열의 n항을 계산하여 마지막8자리 출력
		int answer = getFibo(n); 
		printf("ANSWER = %d\n", answer);
	}

	//불필요한 배열은 가능하면 할당해제해주는 것이 좋다.
	FIBONACCI_TABLE.clear();

	return 0;

}

