#include<cstdio>
#include<iostream>

using namespace std;

/*
배열의 N개의 원소가 연속적인 정수 수열로 표현될 수 있는지 판단하는 함수
data
n
return n

연속적인 수열 - 항상 i번째 숫자의 값이 i+1번째 숫자보다 1이 작은 정수로 이루어진 수열을 의미

연속적인 수열이라면 최대 값 - 최소 값이 n-1(배열크기-1)과 일치해야 함을 염두

*/

bool isConsecutive(int data[], int n)
{
	//첫번째 원소로 초기화
	int max_data = data[0]; 
	int min_data = data[0];

	//max-min=n-1인지 판단해야함.
	for (int i = 0; i < n; i++) //최대, 최소를 구하는 반복문
	{
		if (max_data <data[i]) //max_data가 i번째 원소보다 작다면
			max_data = data[i]; //i번째 원소로 업데이트
		
		//max_data와 min_data는 별개이므로 두 조건문 모두 수행될 수 있으므로 else 사용하지 않음.
		if (min_data > data[i])  //min_data가 i번째 원소보다 크다면
			min_data = data[i]; //i번째 원소로 업데이트
	}

	if (max_data-min_data == n - 1) 
		return true;//같다면 연속적
	else
		return false;//아니라면 불연속적
}

int main()
{
	int n; //에피소드의 수 n
	int* data;//배열 

	scanf("%d", &n); //n 입력받음
	data = new int[n]; //n만큼 배열 할당

	for (int i = 0; i < n; i++)//배열에 에피소드의 번호 입력 받음
	{
		scanf("%d", &data[i]);
	}

	bool result = isConsecutive(data, n); //정렬하면 연속된 수열로 표현될 수 있는지 여부 판별

	if (result) //표현할 수 있음
	{
		printf("YES");
	}
	else { //표현할 수 없음
		printf("NO");
	}

	delete[] data;
	return 0;
}