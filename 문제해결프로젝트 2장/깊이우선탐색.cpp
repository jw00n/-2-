#include<iostream>

using namespace std;
 
int maps[10][10]; //maps - ������� ����
int visited[10] = { 0 }; //�湮������ ������ �迭
int num; //���� ������ ������  num

//������� map �ʱ�ȭ�� init()
void init() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maps[i][j] = 0;
}


void dfs(int v) //���̿켱Ž��
{
	cout << v << endl; //ó���� 1�� ���� ���� �Ű����� v ���
	visited[v] = 0; //0���� �ʱ�ȭ -> v�� ���ؼ��� �̹� ��������Ƿ� �ϴ�  if������ ��������ʰ��ϱ� ����
	for (int i = 0; i <= num; i++)//num���� �ݺ��ϸ鼭
	{
		if (maps[v][i] && visited[i]) //1 && 1 �϶� ��������� �Լ�ȣ��
			dfs(i); //����� ������ ���ܱ��� �����.
	}
}

int main(void) 
{
	int v1, v2; //������ �Է¹��� ���� 
	init(); //maps - ���� ������ ������ 2�����迭 ó�� 0���� �ʱ�ȭ
	cin >> num;  //������ ���� =num(��������) �Է¹��� 
	for (int i = 0; i < num; i++) {
		cin >> v1 >> v2; //�������� �Է� �ް�
		maps[v1][v2] = maps[v2][v1]=1;  // ������ �׷����̹Ƿ� �� �� 1�� ������Ʈ
		visited[v1] = visited[v2] = 1; //�湮���� = 1 �� ǥ��
	}//������� �Ϸ�

	dfs(1); //1������ �����Ѵٴ� ���� ���ڸ� �־� ���̿켱Ž�� ����

	return 0;

}