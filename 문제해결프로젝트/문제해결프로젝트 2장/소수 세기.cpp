#include<cstdio>
#include<vector>

using namespace std;

//소인수 분해를 빠르게

class Sieve {
public:
	int maximumValue; //에라토스데네스의 체에서 다룰 가장 큰 범위의 값
	vector<bool> isPrime; //각 숫자별 소수 여부


	Sieve(int maximumValue) { //maximumValue = 1백만
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //크기는 인덱스가 0부터 시작하니 1을 증가한 값으로, false로 초기화
		this->fillSieve();
		
	}

	/* 
	param num
	return 'num'이 소수라면 true, 그렇지 않으면 false
	*/

	bool isPrimeNumber(int num) const {
		
		return this->isPrime[num];
	
	}

	/*
	isPrime 배열의 값을 채우는 함수
	*/

	void fillSieve() { //알고리즘 수행
		isPrime.assign(this->maximumValue, true); //처음에는 모두 소수(true)라고 저장한다.
		
		isPrime[0] = false; //0과 1은 소수가 아니므로 미리 처리한다.
		isPrime[1] = false;

		for (int num = 2; num <= maximumValue; num += 1) {
			
			//[2,N] 사이의 모든 자연수 num에 대해
			if (isPrime[num] == false) {
				
				//이미 소수가 아니라고 체크되었다면 건너 뛴다.
				continue;
			}

			/*
			이 때 num은 소수라면?
			그러므로 num의 모든 배수를 소수가 아니라고 체크한다.
			num보다 작은 k에 대해 mul=num*num으로 표현되는 모든 자연수는 이미 처리되었다.
			그러므로 mul = num*num 부터만 처리하면 된다. 오버플로우 고려,최대 100만의 제곱까지 -> long long 타입
			mul값을 num의 배수만큼 증가시키기때문에 시간복잡도를 줄일 수 있다.
			*/

		
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num)
			{
				
				//이때 mul에 대해서, mul을 나누는 최초의 소인수 num이 등장한다.
				//이 정보를 저장해두면 소인수 분해를 할 때 유용하다.
				int index = (int)mul;
				
				//인덱스참조과정에서 *에러발생하는 부분 
				isPrime[index] = false; //소수가 아니라고 false로 업데이트

			}
			
		}
	}

};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes; //소수 저장용 벡터 컨테이너

	for (int num = from; num <= to; num += 1) { //from ~ to까지 num을 증가시키며 반복하면서
		if (sieve.isPrimeNumber(num)) { //소수 여부를 확인하여
			primes.push_back(num);//소수이면 num을 primes에 추가
		}
	}

	return primes;
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	scanf("%d %d", &L, &R);

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //소수구별을 위한 함수 호출

	printf("Case #%d:\n", caseIndex);//케이스 번호 출력
	printf("%d\n", (int)allPrimeNumbers.size()); //allPrimeNumbers.size() =소수의 개수
}

int main() {
	const int MAX_VALUE = 100000; //1~1백만 전처리 100000
	Sieve sieve = Sieve(MAX_VALUE);//전처리를 통해서 미리 수행해서 쉽게 호출에 용이

	int caseSize; //테스트 케이스 사이즈 수 입력받음
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve); //프로세스 진행 
	}
	return 0;
}