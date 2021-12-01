#include<cstdio>
#include<iostream>

using namespace std;

int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1; // 없을경우 -1 출력

	for (int i = n-1; i>=0; i--) 
		//오름차순으로 정렬되어있으므로 뒤에서부터 찾는게 빠름
	{
		if (month[i] == m) //달이 일치하면
		{
			maxHeight = height[i]; //가장 큰 키 입력
			break;
		}
	}

	return maxHeight; //month[i]== m인 가장 큰 height[i]

}


/*
n 도토리의 수
m 찾고자하는 달
height 각 도토리의 키
month 각 도토리의 출생 월
*/

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n); //도토리의 수 입력받음
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++) //공백으로 구분된 각 도토리의 키 저장
	{
		scanf("%d", &height[i]); 
	}

	for(int i=0; i<n; i++) //공백으로 구분된 각 도토리의 출생 월 저장
	{
		scanf("%d", &month[i]);
	}

	scanf("%d", &m); //현재 달을 나타내는 1~12사이의 자연수

	int answer = getMaximumHeight(height, month, n, m); //가장 큰 키를 찾는 함수호출

	printf("%d\n", answer); //가장 큰 키 출력

	delete[] height;
	delete[] month;
	return 0;
}