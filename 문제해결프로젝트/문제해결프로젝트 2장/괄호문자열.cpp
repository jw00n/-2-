#include<iostream> //�����
#include<string> //���ڿ�
#include<stack> //���� ���� 
#include<vector> //���� ����

using namespace std;

class Parenthesis {
public:
	bool type; //���� ��ȣ -> true / ���� ��ȣ -> false
	int index; //�ش� ��ȣ�� �ε���

	Parenthesis(int index, bool type) { //type�� ���� ���� ��ȣ���� ������ȣ���� �Ǵ�
		this->index = index;
		this->type = type;
	}


	Parenthesis(int index, char c) { 
		this->index = index;
		if (c == '(') {//'(' ���� ��ȣ -> true
			this->type = true;
		}
		else { //')' ���� ��ȣ, �� ��Ÿ���̶��  -> false
			this->type = false;
		}
	}

};

/*
��ȣ���� ������ ���ʷ� �迭�� �־��� ��, �ùٸ� ��ȣ ���ڿ����� �Ǵ��ϴ� �Լ�

param n - ��ȣ ���ڿ��� ����
param parentheses -��ȣ ���ڿ� ���� �迭
return
*/


bool isValidParentheses(const vector<Parenthesis>& parentheses) {//���ڷ� ���ͺ����� ����
	//������ �̿��� ���� ¦�� ã�� ���� ���� ��ȣ�鸸 ����.
	//���� ��ȣ�� ������ ž�� ����� ���� ��ȣ�� ������ ����.
	//ž ���� ������ �̷������ --> ���ú����� ����

	stack<Parenthesis> st; //Ŭ������ Ÿ�Լ���

	for (int i = 0; i < parentheses.size(); i++) { //size =������ŭ �ݺ�
		//���ʺ��� �������� ��ȣ�� ���ʷ� ��ȸ�Ѵ�.
		//���� �����̹Ƿ� ��� ���� ���� ����

		Parenthesis p = parentheses[i]; //���� ���� p�� �ӽ÷� �Ҵ����� ����

		/* true <- ���� ��ȣ // ���� ��ȣ -> false*/

		//���� ��ȣ���
		if (p.type == true) {
				st.push(p); //¦�� ã�������� ���ÿ� �����Ѵ�
		}

		//���� ��ȣ p�� ���Ͽ�
		else if (p.type == false) {

			if (st.size() > 0) {//pop()�� �ϱ����� ���ÿ� ����Ǿ��ִ� �������� Ȯ���ϱ����� size()���� 0���� ū�� Ȯ���Ѵ�. 
				//���� �������� �߰��� ���� ��ȣ�� ¦�� ���� �� �����Ƿ� �����Ѵ�.
				st.pop(); 
			}
			else { 
				//¦�� ���� �� �ִ� ���� ��ȣ�� ���ٸ� �ùٸ��� ���� ��ȣ ���ڿ��̴�. = ���� ��ȣ�� ���Դµ� ���� ���� ���� -> ������ȣ x
				return false;
			}
		}
	}

	if (st.size() > 0) { //Ȥ�� st.empty() ==0
		//�� ������ �����ϰ� �������� ���� ���ÿ� ¦�� ã�� ���� ���� ��ȣ�� �����ִ�
		return false; //false ����
	}

	return true; //false��츦 ������ �������� ���� true ����

}

void process(int caseIndex) {
	string str; //��ȣ ���ڿ��� �Է¹��� string ����
	cin >> str; //���ڿ��� �Է¹޴´�.

	vector<Parenthesis> parentheses;
	//�迭���� ���Ͱ� ���ؼ� ���͸� ����Ѱ�
	//����Ÿ���� Ŭ������ ����
	//���ʹ� (front ~back) ��� ��ġ�� ���� ���� ����(���� �迭�� ����Ѵ�.)
	//������ ž-��ġ�� ���Ҹ� ���ٰ����ϴ�. //���ʴ�� �����ؾ��Ѵ�.



	//�ݺ����� ���� Parenthesis(i, str[i])�� ��(1 or 0)�� push_back�� �̿��ؼ� ���� �� ���� �ݺ��Ͽ� ����ִ´�.
	for (int i = 0; i < str.length(); ++i) {
		parentheses.push_back(Parenthesis(i, str[i])); //i = index , str[i] = ������ȣor������ȣ
	}

	bool isValid = isValidParentheses(parentheses); //��ȿ���� �ƴ����� �˾ƺ��� �Լ� isValidParentheses

	if (isValid) { //true = VPS -> YES ���
		cout << "YES" << endl;
	}
	else { //false�� ���  NO ���
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize; // = T ,�׽�Ʈ ������ ����  
	cin >> caseSize; //�Է¹޴´�.

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { //���̽� ���ڸ�ŭ �Լ� process ȣ��
		process(caseIndex);
	}

}
