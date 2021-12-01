#include<iostream>
#include<set> //�ߺ����θ� ���� �Ǵ��ϱ� ���� set -> �����Ͱ� �����Ǿ������� Ž���� ����

using namespace std;

int main() {
	int n; //�������� ����
	cin >> n; //�Է¹���

	//integers = �������� ������ ��� ������ ������ ����
	set<int> integers; //int�� set ���� -> �⺻) ������������ ���ĵ�
 
	for (int i = 0; i < n; ++i) { //n�� �ݺ��ϸ鼭 
		int x;//x=���� �Է¹���.
		cin >> x;

		/*
		C++ set�� find �޼ҵ�� 
		ã�� ���ڰ�
		�ִٸ� �ش� iterator��,
		���ٸ� end() iterator�� ��ȯ�Ѵ�.
		*/

		//set����.count(element) -> element�� set�����ȿ� �ִٸ� 1/������ 0
		if (integers.count(x) > 0) { //�̹� ã�� ���� �ִٸ� integers.find(x) != s.end()
			cout << ">> DUPLICATED" << endl; //�ߺ� ǥ��
			//cout  <<*integers.find(x) << endl; 
		}
		else{ //ã�� ���� ���ٸ�(�ߺ��� �ƴϴ�)
			integers.insert(x); //set�� ��(x)�� ����Ѵ�.
			cout << ">> OK" << endl; //��ϵǾ��ٴ� ������ ok ���
		}
	}

	return 0;
}

