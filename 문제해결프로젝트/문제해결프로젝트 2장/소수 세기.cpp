#include<cstdio>
#include<vector>

using namespace std;

//���μ� ���ظ� ������

class Sieve {
public:
	int maximumValue; //�����佺���׽��� ü���� �ٷ� ���� ū ������ ��
	vector<bool> isPrime; //�� ���ں� �Ҽ� ����


	Sieve(int maximumValue) { //maximumValue = 1�鸸
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //ũ��� �ε����� 0���� �����ϴ� 1�� ������ ������, false�� �ʱ�ȭ
		this->fillSieve();
		
	}

	/* 
	param num
	return 'num'�� �Ҽ���� true, �׷��� ������ false
	*/

	bool isPrimeNumber(int num) const {
		
		return this->isPrime[num];
	
	}

	/*
	isPrime �迭�� ���� ä��� �Լ�
	*/

	void fillSieve() { //�˰��� ����
		isPrime.assign(this->maximumValue, true); //ó������ ��� �Ҽ�(true)��� �����Ѵ�.
		
		isPrime[0] = false; //0�� 1�� �Ҽ��� �ƴϹǷ� �̸� ó���Ѵ�.
		isPrime[1] = false;

		for (int num = 2; num <= maximumValue; num += 1) {
			
			//[2,N] ������ ��� �ڿ��� num�� ����
			if (isPrime[num] == false) {
				
				//�̹� �Ҽ��� �ƴ϶�� üũ�Ǿ��ٸ� �ǳ� �ڴ�.
				continue;
			}

			/*
			�� �� num�� �Ҽ����?
			�׷��Ƿ� num�� ��� ����� �Ҽ��� �ƴ϶�� üũ�Ѵ�.
			num���� ���� k�� ���� mul=num*num���� ǥ���Ǵ� ��� �ڿ����� �̹� ó���Ǿ���.
			�׷��Ƿ� mul = num*num ���͸� ó���ϸ� �ȴ�. �����÷ο� ���,�ִ� 100���� �������� -> long long Ÿ��
			mul���� num�� �����ŭ ������Ű�⶧���� �ð����⵵�� ���� �� �ִ�.
			*/

		
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num)
			{
				
				//�̶� mul�� ���ؼ�, mul�� ������ ������ ���μ� num�� �����Ѵ�.
				//�� ������ �����صθ� ���μ� ���ظ� �� �� �����ϴ�.
				int index = (int)mul;
				
				//�ε��������������� *�����߻��ϴ� �κ� 
				isPrime[index] = false; //�Ҽ��� �ƴ϶�� false�� ������Ʈ

			}
			
		}
	}

};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes; //�Ҽ� ����� ���� �����̳�

	for (int num = from; num <= to; num += 1) { //from ~ to���� num�� ������Ű�� �ݺ��ϸ鼭
		if (sieve.isPrimeNumber(num)) { //�Ҽ� ���θ� Ȯ���Ͽ�
			primes.push_back(num);//�Ҽ��̸� num�� primes�� �߰�
		}
	}

	return primes;
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	scanf("%d %d", &L, &R);

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //�Ҽ������� ���� �Լ� ȣ��

	printf("Case #%d:\n", caseIndex);//���̽� ��ȣ ���
	printf("%d\n", (int)allPrimeNumbers.size()); //allPrimeNumbers.size() =�Ҽ��� ����
}

int main() {
	const int MAX_VALUE = 100000; //1~1�鸸 ��ó�� 100000
	Sieve sieve = Sieve(MAX_VALUE);//��ó���� ���ؼ� �̸� �����ؼ� ���� ȣ�⿡ ����

	int caseSize; //�׽�Ʈ ���̽� ������ �� �Է¹���
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve); //���μ��� ���� 
	}
	return 0;
}