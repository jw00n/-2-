#include<iostream>

using namespace std;
 
int maps[10][10]; //maps - 인접행렬 변수
int visited[10] = { 0 }; //방문했음을 보여줄 배열
int num; //간선 개수를 저장할  num

//인접행렬 map 초기화용 init()
void init() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0;
}


void dfs(int v) //깊이우선탐색
{
	cout << v << endl; //처음엔 1의 값을 가진 매개변수 v 출력
	visited[v] = 0; //0으로 초기화 -> v에 대해서는 이미 수행됐으므로 하단  if문에서 수행되지않게하기 위해
	for (int i = 0; i <= num; i++)//num까지 반복하면서
	{
		if (maps[v][i] && visited[i]) //1 && 1 일때 재귀적으로 함수호출
			dfs(i); //재귀적 구조로 말단까지 수행됨.
	}
}

int main(void) 
{
	int v1, v2; //간선을 입력받을 변수 
	init(); //maps - 간선 정보를 저장할 2차원배열 처음 0으로 초기화
	cin >> num;  //간선의 개수 =num(전역변수) 입력받음 
	for (int i = 0; i < num; i++) {
		cin >> v1 >> v2; //간선정보 입력 받고
		maps[v1][v2] = maps[v2][v1]=1;  // 무방향 그래프이므로 둘 다 1로 업데이트
		visited[v1] = visited[v2] = 1; //방문했음 = 1 로 표시
	}//인접행렬 완료

	dfs(1); //1번부터 시작한다는 뜻의 인자를 주어 깊이우선탐색 시작

	return 0;

}