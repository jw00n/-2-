#include<iostream> //입출력
#include<string> //문자열
#include<stack> //스택 변수 
#include<vector> //벡터 변수

using namespace std;

class Parenthesis {
public:
	bool type; //열린 괄호 -> true / 닫힌 괄호 -> false
	int index; //해당 괄호의 인덱스

	Parenthesis(int index, bool type) { //type을 통해 열린 괄호인지 닫힌괄호인지 판단
		this->index = index;
		this->type = type;
	}


	Parenthesis(int index, char c) { 
		this->index = index;
		if (c == '(') {//'(' 열린 괄호 -> true
			this->type = true;
		}
		else { //')' 닫힌 괄호, 및 기타값이라면  -> false
			this->type = false;
		}
	}

};

/*
괄호들의 정보가 차례로 배열로 주어질 때, 올바른 괄호 문자열인지 판단하는 함수

param n - 괄호 문자열의 길이
param parentheses -괄호 문자에 대한 배열
return
*/


bool isValidParentheses(const vector<Parenthesis>& parentheses) {//인자로 벡터변수를 받음
	//스택을 이용해 현재 짝을 찾지 못한 열린 괄호들만 저장.
	//닫힌 괄호가 나오면 탑에 저장된 열린 괄호를 삭제해 나감.
	//탑 원소 삭제만 이루어지니 --> 스택변수로 선언

	stack<Parenthesis> st; //클래스토 타입선언

	for (int i = 0; i < parentheses.size(); i++) { //size =개수만큼 반복
		//왼쪽부터 오른족의 괄호를 차례로 조회한다.
		//벡터 변수이므로 모든 원소 접근 가능

		Parenthesis p = parentheses[i]; //벡터 값을 p에 임시로 할당해준 다음

		/* true <- 열린 괄호 // 닫힌 괄호 -> false*/

		//열린 괄호라면
		if (p.type == true) {
				st.push(p); //짝을 찾을때까지 스택에 보관한다
		}

		//닫힌 괄호 p에 대하여
		else if (p.type == false) {

			if (st.size() > 0) {//pop()을 하기전에 스택에 저장되어있는 상태인지 확인하기위해 size()값이 0보다 큰지 확인한다. 
				//가장 마지막에 추가된 열린 괄호와 짝을 맞출 수 있으므로 제거한다.
				st.pop(); 
			}
			else { 
				//짝을 맞출 수 있는 열린 괄호가 없다면 올바르지 않은 괄호 문자열이다. = 닫힌 괄호가 나왔는데 지울 값이 없다 -> 열린괄호 x
				return false;
			}
		}
	}

	if (st.size() > 0) { //혹은 st.empty() ==0
		//위 과정을 수행하고 났음에도 아직 스택에 짝을 찾지 못한 열린 괄호가 남아있다
		return false; //false 리턴
	}

	return true; //false경우를 제외한 나머지의 경우는 true 리턴

}

void process(int caseIndex) {
	string str; //괄호 문자열을 입력받을 string 변수
	cin >> str; //문자열을 입력받는다.

	vector<Parenthesis> parentheses;
	//배열보단 벡터가 편해서 벡터를 사용한것
	//변수타입을 클래스로 정의
	//벡터는 (front ~back) 모든 위치의 원소 접근 가능(동적 배열로 사용한다.)
	//스택은 탑-위치의 원소만 접근가능하다. //차례대로 접근해야한다.



	//반복문을 통해 Parenthesis(i, str[i])의 값(1 or 0)을 push_back을 이용해서 벡터 맨 끝에 반복하여 집어넣는다.
	for (int i = 0; i < str.length(); ++i) {
		parentheses.push_back(Parenthesis(i, str[i])); //i = index , str[i] = 닫힌괄호or열린괄호
	}

	bool isValid = isValidParentheses(parentheses); //유효한지 아닌지를 알아보는 함수 isValidParentheses

	if (isValid) { //true = VPS -> YES 출력
		cout << "YES" << endl;
	}
	else { //false인 경우  NO 출력
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize; // = T ,테스트 데이터 개수  
	cin >> caseSize; //입력받는다.

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) { //케이스 숫자만큼 함수 process 호출
		process(caseIndex);
	}

}
