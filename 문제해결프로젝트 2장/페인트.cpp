#include <cstdio>
#include<vector>

using namespace std;

const int MAX_SENT_NUMBER = 1000; //1000������ �ڿ���
const int MAX_COLOR_NUMBER = 100; //0~99���� ����

//�¼����� �ѹ� ��ĥ�ϴ� �̺�Ʈ�� ���� ����
class Painting {
public:
	int left; //��ĥ�� ���� ���� �¼��� ��ȣ
	int right; //������
	int color; //ĥ�� ������ ��ȣ

	Painting(){}

	Painting(int left, int right, int color) {
		this->left = left;
		this->right = right;
		this->color = color;
	}



};


/* 
* data[0] ~data[n-1]�� ������ ��ȣ�鿡 ���� �󵵼� ���̺��� ä����Լ�
 
param data
param n
table table[x] := data �迭���� x�� ������ Ƚ�� 
*/

void fillFrequencyTable(int data[], int n, int table[]) {
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) { //0���� �ʱ�ȭ
		table[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int color = data[i]; //������ ���� color�� �����ϰ�
		table[color] += 1; //�׸� �ε����� �ϴ� table�� 1�� ����
	}

}

void solve(int n, int m, const Painting* paintings) {
	int* seats = new int[n]; //ũ�� n�� �¼� �迭 
	for (int i = 0; i < n; i++)
	{//ó�� �¼��� ���� 0�� ������ ĥ�����ִ�. 0���� �ʱ�ȭ
		seats[i] = 0;
	}
	
	//��ĥ �������� �־��� ������� �� �¼��� ��ĥ�Ѵ�.
	for (int i = 0; i < m; i++) {

		//��� ��ĥ ���� p�� ���Ͽ� ���ʴ��
		const Painting &p = paintings[i];

		//�� ������  �������� �¼��� ���� ������Ʈ ���ش�.
		for (int j = p.left; j <= p.right; j++) {
			seats[j] = p.color; //�÷����� �¼��迭�� ������Ʈ
		}
	}

	//��� ��ĥ�� �Ϸ��� ������ ���������� ����Ͽ�
	//��� ���� ���� �󵵼� ���̺��� ����Ѵ�.
	int* table = new int[MAX_COLOR_NUMBER];
	fillFrequencyTable(seats, n, table); //������׷� ���ϴ� �Լ� ȣ��

	//�ʱ�ȭ
	int minColor = seats[0]; //���� ���� ������ ����
	int maxColor = seats[0]; //���� ���� ������ ����

	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) {
		if (table[color] == 0) { //�ѹ��� �������� ���� ������ ��� ���ܽ�Ű�Ƿ� �Ѿ
			continue;
		}

		//�� �� �̻� ������ ��� ���� color�� ���Ͽ�

		if(table[minColor]> table[color]){
			//���� ���� ������ ���� ���� ���ų� color�� �� ���� ������ ���
			minColor = color; //������Ʈ
		}
		if (table[maxColor] < table[color]) {
			//���� ���� ������ ���� ���� ���ų� color�� �� ���� ������ ���
			maxColor = color; //������Ʈ
		}
	}
	
	//���
	printf("%d\n", maxColor);
	printf("%d\n", minColor);

	delete[] table;
}

int main() {
	int n, m; //�¼� ���� n, �÷� ���� m
	scanf("%d %d", &n, &m); //�Է�

	//paintings[i] := i ��° �Ͼ ��ĥ �̺�Ʈ�� ����
	Painting* paintings = new Painting[n]; //ũ��� n����
	


	for (int i = 0; i < m; ++i) { // left, right , color ���� �Է¹���
		
		scanf("%d", &paintings[i].left); 
		scanf("%d", &paintings[i].right);
		scanf("%d", &paintings[i].color);

		//�¼��� ��ȣ�� 1������ �����ϹǷ�, 0~ (n-1)������ ���߱� ���Ͽ� 1�� ���ش�.
		paintings[i].left -= 1;
		paintings[i].right -= 1;
	}

	//���� ���ϱ�
	solve(n, m, paintings);

	return 0;
}


