#include<iostream> //�����
#include<vector> //���� ����
#include<queue> //ť ����

using namespace std;

class Player {
public:
	int index; //���

	Player(int index) { //�μ��� �޾� �ε����� ����
		this->index = index;
	}
};


/*
 �����۽� ������ �����Ͽ� ���÷��̾ ���ŵ� ������ ����Ʈ�� ��ȯ�ϴ� �Լ�

 param 
 n  �÷��̾��� ��
 m �� �ϸ��� �ǳ� �� ����� ��
 players �¼��� �ɾ��ִ� ������� �־����� �÷��̾� ����

 return
*/

vector < Player> getDeadPlayerList(int n, int m, const vector<Player>& players) {
	//���� ���ӿ��� ���ܵ� �÷��̾���� ����Ʈ
	vector<Player> deadPlayers;

	//���� ���ӿ��� ���ܵ��� �ʴ� �÷��̾���� ����Ʈ
	queue<Player> que;

	//�μ��� ���� ���� players ������ que�� �����Ѵ�.
	for (int i = 0; i < n; i += 1) {
		que.push(players[i]); //1 2 3 4 5 6 7
	}


	/*
	�ǳʶ۶� que�� ���� ���� -> ������ �ڿ��� , ť�� �տ��� ���ܸ� ��Ų��.
	�����͸� ��������� ������ �� �ڿ��� �Ͼ�� ������ 
	������ �� �տ��� �Ͼ�� ������
	ť�� ���
	*/

	//���� ����Ŭ�� ���� ������, ������ ������ �̿��ؼ� ��� ��ġ ���ڸ� �������� ã�Ƽ� ������ �� �ִ�.

	//n�� �ݺ��ϸ鼭 ��� ���ܽ�Ŵ
	for (int i = 0; i < n; i++) {
		//m-1���� ����� �ǳʶڴ�.
		//ex) m=3 �̸� 3->6->2... que.size()=7 //1�� �������� 7�� ���� �������� 2 �״��� �ٽ� 1�� �����ش�.
		int jump = 1 + (m - 1) % que.size();
		for (int j = 0; j < jump - 1; j += 1) {
			Player p = que.front(); //ť ù ��° ���� �����ϱ����� �ӽ÷� ������ ��
			que.pop(); //����
			que.push(p); //p�� �ӽ������� ���� �־��ش�.
						 //ex) 1��° �ݺ� 2 3 4 5 6 7 1 ->2��°)  3 4 5 6 7 1 2 
		}//�Ϸ�Ǹ� ������ ���� �� ù��°�� ���� �ȴ�.


		//m��° ����� ���ӿ��� �����Ѵ�.
		Player dead = que.front(); //������ ����� dead�� �־��ְ�
		que.pop();//����

		deadPlayers.push_back(dead); //���� ����Ʈ�� �߰��Ѵ�.
	}

	return deadPlayers; 
}

void process(int caseIndex) {
	int n, m; //n���� ��� �� n // M��°�� m
	cin >> n >> m; //�Է¹޴´�.

	vector<Player> players;// ���ͺ��� ���� //������ Ÿ�� -> player��
	for (int i = 0; i < n; i++) { //player�� �ε����� �����Ͽ� ���Ϳ� �����ϴ� �ݺ���
		players.push_back(Player(i + 1)); //���ڴ� 1���� �����̹Ƿ� +1�� ���ش�.
	}

	//���ܵ� ��� ����Ʈ�� �Լ��� �˾Ƴ��� ���ͺ��� deadPlayers�� ����
	vector<Player> deadPlayers = getDeadPlayerList(n, m, players); 

	//����ϴ� �ݺ���
	for (int i = 0; i < n; i++) {
		if (i > 0) { //����
			cout << " ";
		}

		//���ܵ� ����� ����Ʈ�� �ε����� ���
		Player p = deadPlayers[i];
		cout << p.index;
	}

	cout << endl; //���� �� �پ�
}

int main() {
	int caseSize; //�׽�Ʈ ���̽� ����
	cin >> caseSize; //�Է¹���

	//�׽�Ʈ ���̽� ���ڸ�ŭ caseIndex�� ����,�ݺ��ϸ鼭 process ȣ��
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}

	return 0;
}