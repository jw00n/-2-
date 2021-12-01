#include<iostream>
#include<queue>

using namespace std;

int map[10][10] = { 0 }; //인접행렬
int visit[10] = { 0 }; //방문 확인용 배열
queue<int> q; //큐 변수
int num, edge_num; //정점, 간선 개수

void bfs(int v) {
	cout << v << endl; //인수로 받은 v 출력
	q.push(v); //큐에 v의 값을 넣어준다.
	while (!q.empty()) { //큐가 비어있지 않는 한, 반복
		int node = q.front(); //int변수 node에 front 값을 저장하고
		q.pop();//삭제
		for (int i = 0; i < num; i++) {//num=간선 개수만큼 반복하면서 map데이터를 보며 
			if (map[node][i] == 1 && visit[i] == 0) {//map[node][i], 간선이 있는지 && 방문을 안 했는지
				visit[node] = 1;//조건에 부합한다면 1로 업데이트해준다.
				cout << i << endl; //i를 출력// 1-2간선이라면 2를 출력해줌.
 				q.push(i); //i 값을 큐에 넣어줌  //처음엔 2,3이 큐에 들어가게 됨.
			}
		}//for문 수행 후에 큐가 비어있지않으면 while문 반복
	}
}

int main() {
	cin >> num >> edge_num; //정점 = num // 간선 =edge_num 입력받음
	for (int i = 0; i < edge_num; i++)
	{
		int v1, v2; //간선의 정보 
		cin >> v1 >> v2;//입력받음
		map[v1][v2] = map[v2][v1] = 1; //무방향이므로 1로 업데이트

	}

	bfs(1); //정점 1부터 너비우선탐색 시작
	return 0;
}