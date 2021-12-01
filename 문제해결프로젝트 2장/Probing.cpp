#include<cstdio>
#include<vector>

using namespace std;

class TicketTable {
public:
	vector<bool> used; 
	int length;

	TicketTable(int length) { //length<-n
		this->length = length;
		this->used.assign(length, false); //false�� �ʱ�ȭ
	}

	
	//������� ȸ����ȣ�� ���޹ް� �� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int findEmptyIndexByUserId(int userId) { //�ε������� �Ѱܹް�
		int index = userId % length; //���� �ʱ⿡ �õ��� Ƽ�� ��ȣ
		while (this->isEmpty(index) == true) { //���� Ƽ�� ��ȣ(true)��� �ǳʶڴ�.
			index = (index + 1) % length; //���� ��ȣ�� �����س�����.   eX_ 2879��� 1�� �����ϸ鼭 false�� ã�������� �ݺ�
		}
		return index; //�ݺ����� ��� ������ ���� �ε����� ã�Ƽ� ��ȯ�Ѵ�.
	}

	/*
	�ش� ���� ��ȣ�� �̹� ��������� ���θ� ��ȯ�ϴ� �޼ҵ�
	*/

	bool isEmpty(int ticketIndex) {
		return this->used[ticketIndex];// ��뿩��<==> used[ticketIndex]
	}
	 //Ƽ�� ��� ���θ� �����ϱ� ���� �޼ҵ�
	void setUsed(int index, bool status) {
		this->used[index] = status;  //true�� ������Ʈ
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
	vector<int> tickets; //���� ����
	TicketTable table = TicketTable(n); //����ü ����

	for (int i = 0; i < m; i++) { 
		int userId = ids[i]; //�ε��� ���� ����
		int ticketIndex = table.findEmptyIndexByUserId(userId); //�ε��� ���� �Ѱ���
		tickets.push_back(ticketIndex); //�ε������� �߰�
		table.setUsed(ticketIndex, true); //���� ���̹Ƿ� true�� ����
	}

	return tickets; // ����
}

int main() {
	//n : ��ü Ÿ���� ��
	//m : ��û ���� ��

	int n, m;
	scanf("%d %d", &n, &m); //�Է¹���
	 
	vector<int> ids(m); //�ε������ ���ͺ��� ����
	for (int i = 0; i < m; ++i) { //���� ������� �Է¹���
		scanf("%d", &ids[i]);
	}

	vector<int> tickets = getTicketNumbers(n, m, ids); //ȸ����ȣ�� �ο��ϴ� �Լ� ȣ��
	for (int i = 0; i < tickets.size(); ++i) {
		printf("%d\n", tickets[i]); //tickets�� ���� ���
	}

	return 0;
}


