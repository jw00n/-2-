#include<cstdio>
#include<vector>

using namespace std;

/*
자연수 N을 구성하는 모든 소인수를 반환하는 함수

param N
return
*/

vector<int> factorize(int n) {
	vector<int> factors; //벡터변수 선언

	for (int div = 2; div * div <= n; div += 1) {// 제곱값으로 , sqrt(N)이하의 자연수 div에 대하여
		while (n % div == 0) {
			//나머지 =0 -> div이 N의 약수 
			//이때, div보다 작은 약수는 모두 처리되었으므로 div 소인수임이 보장된다.

			//소인수 목록에 div을 추가한다..
			factors.push_back(div);

			//N에서 div를 소거해준다.
			//그러므로 이후에는 div을 제외한 소인수를 찾게된다.
			n /= div;
		}

	}

	if (n > 1) {//소인수를 찾지 못하고 남아있는 N이 존재한다면, 소수일 수 밖에 없다.
		factors.push_back(n);//이를 소인수에 추가한다
	}

	return factors;
}

void process(int caseIndex) {
	int n; //소인수분해할 숫자를 입력받음
	scanf("%d", &n);

	vector<int> factors = factorize(n); //factorize 함수 호출

	printf("#%d:\n", caseIndex); //case 번호 출력
	for (int i = 0; i < factors.size(); ++i) { //공백출력
		if (i > 0) {
			printf(" ");
		}
		printf("%d", factors[i]); //소인수분해 결과 출력
	}
	printf("\n");

}

int main() {
	int caseSize; //테스트케이스 입력받음
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex); //프로세스 함수 호출
	}
	return 0;
}