#include<cstdio>

using namespace std;

const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
public:
	//ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getRowByIndex(int index) {
		//ĭ�� ��ȣ�� ���� ���� ������ �����ϹǷ� ������ ����� �� �ִ�.
		return (index - 1) / 9 + 1;
		//9�� ���� ���� �̿��� ���� ���Ѵ�.  
	}

	//ĭ�� ��ȣ�� ���� ��ȣ�� ����ϴ� �޼ҵ�
	int getColByIndex(int index) {
		return (index - 1) % 9 + 1;
		//�������� ���ؼ� ���� ���Ѵ�.
	}

	//ĭ�� ��ȣ�� �׷��ȣ�� ����ϴ� �޼ҵ� //���ڸ� ��,�� ���� �Ѱ��ִ� ����� �� ����.
	int getGroupByIndex(int index) {
		int r = getRowByIndex(index);
		int c = getColByIndex(index);
		return getGroupByPosition(r, c);
	}


	//ĭ�� ��ġ(��, ��)�� �׷� ��ȣ�� ����ϴ� �޼ҵ�
	int getGroupByPosition(int row, int column) {
		//���� ��ȣ�� ����, �ش� �࿡ �����ϴ� �׷�� �� ���� ���� �׷��� ��ȣ�� �� �� �ִ�.
		int left = ((row - 1) / 3) * 3 + 1; //456 -> 345�� ���� /3 , *3 ,+1�� 4���׷쿡 ��Ī

		//���� ��ȣ�� ����, �ش� �࿡ �����ϴ� �׷�� �� �� ��° �׷쿡 ���ϴ� �� �� �� �ִ�.
		int offset = ((column - 1) / 3);  
		return left + offset; //���� ���� �׷� ��ȣ�� ���Ѵ�.
	}

	//ĭ�� ��ġ(��, ��)�� ĭ�� ��ȣ�� ����ϴ� �޼ҵ�
	int getIndexByPosition(int row, int column) {
		//��� �� ��ȣ�� �˸� �ݴ�� �ε����� ���� ����� �� �ִ�.
		return (row - 1) * 9 + (column - 1) % 9 + 1;
	}
};

void process(int caseIndex) {
	int index; //�ε��� ������ ���ڸ� �Է¹���
	scanf("%d", &index);

	SudokuBoard board = SudokuBoard(); //�������� ������ 

	//ĭ�� ��ȣ�� ��,��,�׷� ��ȣ�� ����Ѵ�.
	int row = board.getRowByIndex(index);  //��
	int col = board.getColByIndex(index); //��
	int group = board.getGroupByIndex(index); //�׷� ��ȣ
	//���
	printf("Case #%d:\n", caseIndex);
	printf("%d %d %d\n", row, col, group);

}


int main() {
	int caseSize; //�׽�Ʈ ���̽� �� �Է�
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) { //1~���̽� ������ �ݺ�
		process(caseIndex);//process �Լ� ���� 

	}
	return 0;
}