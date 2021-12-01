#include<cstdio>
#include<iostream>

using namespace std;

/*
중복을 제외한 숫자의 종류의 수를 계산하는 함수
data 원본 배열
n 원본 배열 크기
return 값은 숫자의 종류의 수
*/

int getElementTypeCount(int data[], int n)
{
	int countType = 0; //고유번호 종류의 수 저장하는 변수

	for (int i = 1; i < n; i++) //-1부터 비교할 수 없으므로 i=1부터 시작
	{//중복 아닐때만 종류 수 증가, 오름차순으로 정렬됐으므로 1 2 1 같은 경우 발생X
		if (data[i - 1] != data[i])//중복확인을 data[i-1]과 data[i]의 불일치 비교	
			countType++; //불일치하다면 종류의 수 변수 +1
	}
	
	return countType+1; //비교횟수에 +1 증가시켜야 종류 수와 일치. 기본 종류의 수는 1이상

}

int main()
{
	int n; //원본 배열의 크기(화보의 수)
	int* data; //원본 배열

	scanf("%d", &n); //데이터 개수 입력받음
	data = new int[n]; //배열크기 할당

	for (int i = 0; i < n; i++) // 고유번호를 공백으로 구분하여 
	{
		scanf("%d", &data[i]); //배열에 저장
	}

	int answer = getElementTypeCount(data, n); //중복을 제외한 숫자의 종류의 수를 계산하는 함수 호출
	printf("%d\n", answer); //출력

	delete[] data;
	return 0;

}
