#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
����
1. �־��� ���� ��ģ ������ ��� ���̴�.
2. ���� ������ �� ���̰� ���� ���� ���� ���� �� 1����
3. �迭�ΰ� �����ΰ�
4. Ʈ���� Ǫ�°� ���� �ʳ�? ������ �����ó�� bfs?

*/


int h, w;
int sum = 0;
vector<int> more;
vector<vector<int>>arr_this(h, vector<int>(w, 0));


//���̸� ����ϴ� �Լ�
void subtract(vector<vector<int>>arrB1, vector<vector<int>>arrB2) {
	vector<vector<int>>result(h, vector<int>(w, 0));
	int row_count = arrB1.size(); //�� ��
	int col_count = arrB1[0].size();  //�� ��


	for (int i = 0; i < row_count; i++) {
		for (int j = 0;j < col_count; j++) {
			result[i][j] = abs(arrB1[i][j] - arrB2[i][j]); //���밪 �����ϰ�
		}
	}
	
	arr_this = result;

}

//���⼭ �ּ� ������ ���� Ʈ�� ���� �ϳ� ã�ƾ���
//��� ���� �Ѱ��ְ�
//cout << "���� 1" << endl;



void compare(int row, int col) {
	cout << "compare" << endl;
	vector<vector<int>>please(h, vector<int>(w, 0));
	cout << "���� please�Ʒ�" << endl;
	please = arr_this;
	vector<int> more;
	cout << "������" << endl;
	cout << row << "<�� // ��>" << col << endl;

	if (row > h-1) { //������ ����� �����ߴٸ� ������
		return ;
	}
	if (row == 0) { //�־��ش� //out of range
		cout << "���� �����???" << endl;
		cout<<"�̰� ������ �Ǵ�?  ="<< please[row][col]<<endl;
		more[row] = please[row][col]; //���� ������
		cout << "���սù�" << endl;
	}

	if (col == 0) {//�� ó�� �� ���

		if (please[row + 1][col] < please[row + 1][col + 1]) //�������� ũ�ٸ�
		{//cout << "���� 1" << endl;
			more[row + 1] = please[row + 1][col];
			//cout << "���� 2" << endl;
			compare(row + 1, col); //������ ����
		}
		else
		{//cout << "���� 3" << endl;
			more[row + 1] = please[row + 1][col + 1];
			//cout << "���� 4" << endl;
			compare(row + 1, col + 1);
		}
	}
	else if (col == w) { //�� ������ �� ���
		if (please[row + 1][col - 1] < please[row + 1][col]) {
			//cout << "���� 5" << endl;
			more[row + 1] = please[row + 1][col - 1];
			//cout << "���� 6" << endl;
			compare(row + 1, col - 1);
		}
		else {
			//cout << "���� 7" << endl;
			more[row + 1] = please[row + 1][col];
			//cout << "���� 8" << endl;
			compare(row + 1, col);
		}
	}
	else { //�׿�, col(1~w-1) 3���� ���� ���ؾ��Ѵ� ������
		//cout << "���� 9" << endl;
		int min_index = min_element(please[row+1].begin()+col-1, please[row+1].end() +col+1)- please[row+1].begin();
		//cout << "���� 10" << endl;
		more[row + 1] = please[row + 1][min_index];//�ּҰ� �־���
		//cout << "���� 11" << endl;
		compare(row+1, min_index);//�ּҰ��� ���� ������ ��� ���� �Ѱ���.
	}

	
}






int main() {
	// h= ������ �� �̹����� ���� (1~100) / w= ������ �ʺ�(1~100)
	cin >> h >> w; //�Է��� �޴´�.

	vector<vector<int>>arrB1(h, vector<int>(w, 0)); //h�� w�� ���� ����1
	vector<vector<int>>arrB2(h, vector<int>(w, 0));// ���� 2


	//�� ����ִ� ��

	//B1
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB1[i][j];
		}
	}

	//B2
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arrB2[i][j];
		}
	}


	subtract(arrB1, arrB2); // ���밪 ���


	//���⼭  compare�� �Ѿ�� result�� �ּҰ� ���� ��ߵ�
	int firstmin_index = min_element(arr_this[0].begin(), arr_this[0].end()) - arr_this[0].begin();
	cout <<"first"<< firstmin_index << endl;

	compare(0, firstmin_index);
	
	
	for (int i = 0; i < more.size(); i++) {
		sum += more[i] * more[i];
	}

	cout << "�հ�= " << sum << endl;
	
	


	/*

	cout << "1��° ����" << endl;
	for (vector<int> vec : arrB1) {

		for (int num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << "2��° ����" << endl;
	for (vector<int> vec : arrB2) {
		for (int num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}



	*/


}