#include<cstdio>
#include<iostream>

using namespace std;

/*
주어진 숫자가 소수인지 판별하는 함수

소수 - 약수가 1과 자신뿐
N
return true 소수라면
return false 소수가 아니라면
*/

bool isPrime(int N)
{
	if (N == 1) return false; //1은 약수 1개이므로 소수 아니므로 false 리턴

	//int cnt = 0; //약수 개수 카운트하는 변수
	for (int i = 2;i * i <= N; i++) 
		//반복문,1은 위에서 했으니 2부터 시작 
		// 2~N까지 반복하는게 아닌 2~루트N까지 하는 이유는 약수가 쌍을 이루기 때문이다.
		//axb= N일때 a는 <=루트N일수밖에 없으므로 중반까지만 검사하는 방법으로도 시간복잡도를 O(n) -> O(n^ 1/2)로 감소시킬수 있다. 표현은 i*i <=N 으로
	{
		if (N % i == 0) //N은 10억까지므로 반복문이 10억번 반복하므로 줄일 필요가 있다.  
			//cnt++; 약수가 존재여부만 판단하면 되므로 cnt 필요없음
			return false; //소수는 약수가 있으면 안되므로 false
	}
	return true; //반복문에서 벗어난다면 true 리턴
}

void testcase(int caseIndex)
{
	int n; //소수인지 판단해야하는 숫자를
	scanf("%d", &n);//입력받음

	bool result = isPrime(n); //소수 판단함수 호출 

	printf("Case #%d\n", caseIndex); //테스트 케이스의 번호(caseIndex) 출력
	if (result) //결과가 
	{
		printf("Yes\n");//true면 yes, 
	}
	else { //아니면 no
		printf("No\n");
	}
}


int main()
{
	int caseSize; //테스트 케이스 개수 
	scanf("%d", &caseSize); //입력 받음
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) 
	{
		testcase(caseIndex); //테스트 케이스 함수 실행
	}

	return 0;
}