#include<iostream>
#include<queue>

using namespace std;

int map[10][10] = { 0 }; //�������
int visit[10] = { 0 }; //�湮 Ȯ�ο� �迭
queue<int> q; //ť ����
int num, edge_num; //����, ���� ����

void bfs(int v) {
	cout << v << endl; //�μ��� ���� v ���
	q.push(v); //ť�� v�� ���� �־��ش�.
	while (!q.empty()) { //ť�� ������� �ʴ� ��, �ݺ�
		int node = q.front(); //int���� node�� front ���� �����ϰ�
		q.pop();//����
		for (int i = 0; i < num; i++) {//num=���� ������ŭ �ݺ��ϸ鼭 map�����͸� ���� 
			if (map[node][i] == 1 && visit[i] == 0) {//map[node][i], ������ �ִ��� && �湮�� �� �ߴ���
				visit[node] = 1;//���ǿ� �����Ѵٸ� 1�� ������Ʈ���ش�.
				cout << i << endl; //i�� ���// 1-2�����̶�� 2�� �������.
 				q.push(i); //i ���� ť�� �־���  //ó���� 2,3�� ť�� ���� ��.
			}
		}//for�� ���� �Ŀ� ť�� ������������� while�� �ݺ�
	}
}

int main() {
	cin >> num >> edge_num; //���� = num // ���� =edge_num �Է¹���
	for (int i = 0; i < edge_num; i++)
	{
		int v1, v2; //������ ���� 
		cin >> v1 >> v2;//�Է¹���
		map[v1][v2] = map[v2][v1] = 1; //�������̹Ƿ� 1�� ������Ʈ

	}

	bfs(1); //���� 1���� �ʺ�켱Ž�� ����
	return 0;
}