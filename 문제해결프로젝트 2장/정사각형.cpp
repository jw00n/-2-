#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

class Point2D {
public:
	int x; //x��ǥ
	int y; //y��ǥ
	int index; //�Է¹޴� ������ �ε���

	Point2D(int index, int x, int y) { //�ε����� ���� �Է¹��� ���
		this->index = index;
		this->x = x;
		this->y = y;

	}

	Point2D(int x, int y) { //�ƴ� ���, 1�� �ʱ�ȭ
		this->index = 1;
		this->x = x;
		this->y = y;
	}

	long long getSquaredDistanceTo(Point2D target) {
		//�� ��ǥ���� �����Ÿ��� ��� = �� ���� ��ǥ�� �մ� ���簢���� ���� 
		long long dx = abs(this->x - target.x); //target.x, target.y�� �Է¹޾Ƽ� ������ ���밪�� ����
		long long dy = abs(this->y - target.y); 
		return dx * dx + dy * dy; //������� �� �����־� ���簢���� ������ ���� ����
	}


	
	double getDistanceTo(Point2D target) {
		//�� ��ǥ���� �Ǽ� �Ÿ��� ���
		long long sqd = this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}


	//Ŭ������ ���������Ƿ� ������ �����ʿ� ����
	bool operator < (const Point2D& other)const {
		//�� ��ǥ�� �켱������ ���ϱ� ���� �� ������

		//x��ǥ�� �ٸ��� x��ǥ�� �������� ���Ѵ�.
		if (this->x != other.x) {
			return this->x < other.x;
		}

		//x��ǥ�� ���ٸ� y��ǥ�� �������� ���Ѵ�.
		return this->y < other.y;
	}


};


long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
	long long answer = 0; // = ���� //x,y�� 1�������� �����̹Ƿ� ���̴�-> long longŸ������ ����
	 
	//��� ���� set�� �����Ѵ�.
	set<Point2D> pSet; //default: less(��������), datatype�� class�̹Ƿ� ��Ұ���(�񱳿���) ���� �ʿ�
	
	//set ���� pSet�� ���� -> �ߺ��� xó��
	for (int i = 0; i < n; i += 1) {
		pSet.insert(points[i]);
	}

	//������ a,b �� ���� ��´�.
	for (int i = 0; i < n; i += 1) {
		Point2D pa = points[i]; //������ ��
		for (int j = 0; j < n; j += 1) {
			Point2D pb = points[j];

			if (i == j) continue; //���� ���� �Ÿ��� 0�̶� �ǹ̾����Ƿ� ���ܽ�Ŵ

			//�� ������ pa�� pb�� �����Ѵ�.
			//���� pa-pb�� ���簢���� �� ���̶�� ����.

			//�� ���ǰŸ�(������ ����)�� ������ ���簢���� ���̰� �ȴ�.
			long long area = pa.getSquaredDistanceTo(pb); //��� �����Լ� getSquared~�� �̿��� ������ ����

			//�̹� ���� �簢������ ���̰� �۴ٸ� ���� ���� ���� �ʿ�����Ƿ� �ǳʶڴ�.
			if (area < answer) 
				continue;

			// *���簢������ �Ǵ��� �ʿ䰡 ���� *
			//pa -> pb ������ x,y ��ǥ�� ���� �Ÿ�(��)�� ���Ѵ�.
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			//���� <dx, dy>�� 90���� ȸ����Ű�� < -dy, dx >�� �ȴ�.
			//pa pb�� ���� < -dy, dx > �� ���� ���� ���簢���� �����ϴ� �� ��
			//pd, pc�� ����� �� �ִ�.
			Point2D pd(pa.x - dy, pa.y + dx);
			Point2D pc(pb.x - dy, pb.y + dx);
			//�� ������� �簢���� ������ A,B,C,D�� �� ���ϰ� ��.

			//pa,pb�� �����״� pb,pc�� �������̹Ƿ� �� ���� pSet�� �����ϴ� ������ �˻��ϸ� �ȴ�. ->������ ���簢���� �� �� ����.
			if (pSet.count(pc) > 0 && pSet.count(pd) > 0) { // O(log2N) ->set���� ������ ���డ������
				//if(pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()){
				//if�� ������ �� �� 1�� ��쿡�� answer(����) ������Ʈ ����
				answer = max(answer, area); //max���� ������Ʈ

			}
		}
	}

	return answer;
}

void process(int caseIndex) {
	int n; //��ǥ�� ���� N
	cin >> n; //�Է¹޴´�.

	vector<Point2D> points; //Ŭ���� Point2D�� ������ ���ͺ��� ����

	//��ǥ�� ������ŭ �ݺ��ϸ�
	for (int i = 0;  i < n; i += 1) {
		int x,y; //x,y��ǥ�� �Է¹���
		cin >> x >> y;
		points.push_back(Point2D(i, x, y)); //���� ������ Ŭ������ �ǵں��� �����س���.
	}

	double answer = getMaximumSquareArea(n, points); //n�� ���ͺ����� �μ��� �Ѱ��־� ����ū ���̸� ���ϴ� �Լ� ȣ��

	//�Ҽ��� ����° �ڸ����� �ݿø��ؼ� ���
	cout << fixed << setprecision(2) << answer << endl;
}

int main() {
	int caseSize; //�׽�Ʈ ���̽� ����
	cin >> caseSize; //���� �Է¹ް�

	//�׽�Ʈ ���̽� ���ڸ�ŭ process ����
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}