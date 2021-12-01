#include<cstdio>
#include<iostream>

using namespace std;


/*
주어진 배열이 오름차순인지 검사하는 함수
data 입력받은 학생들의 키 저장 배열
n 데이터의 수
return 값은 T or F
*/
bool isOrdered(int data[], int n)
{
	int count = 0; 

	for (int i = 0; i < n-1; i++) { //비교횟수를 참작하여 i는 n-1 미만으로. n으로하면 배열범위 넘는 문제 발생
		if (data[i] > data[i + 1]) //i번째와 j+1번째를 비교하며 오름차순인지 확인
		{
			count++; //i번째가 더 크다면 count 1증가
			break;
		}
	}

	if (count > 0) //하나라도 있는 경우 false
		return false;
	else //없다면 오름차순이므로 true
		return true;

}

int main()
{
	int n;
	int* data;

	scanf("%d", &n); //학생 수 입력
	data = new int[n]; //학생 수 n만큼 배열할당

	for (int i = 0; i < n; i++) //반복문을 돌며 data[i]에 n명의 각 학생의 키를 저장
	{
		scanf("%d", &data[i]);
	}

	bool result = isOrdered(data, n); //오름차순 여부를 확인하는 함수 호출

	if (result) //TRUE일 경우
	{
		printf("YES");
	}
	else { //FALSE일 경우
		printf("NO");
	}

	delete[] data;
	return 0;
}