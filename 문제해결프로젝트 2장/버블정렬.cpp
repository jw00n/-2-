#include<cstdio>
#include<iostream>

using namespace std;

void bubbleSort(int data[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		int negativecount = 0; //오름차순을 부정하는 쌍의 수
		for (int j = 0; j < n - 1 - i;j++) {//i가 한번씩 반복될때마다 오른쪽 끝의 값은 점점 차므로 n-1에서 n-1-i까지만 반복하면 된다.
		//오름차순을 부정하는 쌍이 나오면 2개 값의 자리를 교환
			
			if (data[j] > data[j + 1]) {
				
				//j번째가 j+1번째보다 크다면 오름차순이 아님
				int tmp = data[j];
				data[j] = data[j + 1]; //교환
				data[j + 1] = tmp;
				negativecount++;
			}
			
		}
		if (negativecount == 0) //처음부터 정렬된 상태라면
			break;
	}
	
}


int main()
{
	int n; //데이터의 개수
	int* data; //데이터 배열 선언

	scanf("%d", &n); //개수 입력받고
	data = new int[n]; //개수만큼 배열 할당

	for (int i = 0;i < n; i++) //배열에 숫자 입력
	{
		scanf("%d", &data[i]);
	}

	bubbleSort(data, n); //버블정렬  실행

	for (int i = 0; i < n; i++) //정렬한 결과를
	{
		if (i > 0)
		{
			printf(" "); //숫자사이에 공백을 넣어서
		}
		printf("%d", data[i]); //정렬된 data 배열을 출력
	}

	delete[] data;
	return 0;
}