#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_LENGTH = 100000; //최대길이는 10만 글자

class MyString {
private:
	char* characters; //문자열
	int length; //문자열의 길이

public:
	
	MyString(const char* str)
	{//구조체 길이, 문자열
	
		this->length = strnlen(str, MAX_LENGTH); //strnlen으로 길이 파악, 최대길이를 넘으면 최대길이가 리턴됨.
		this->characters = new char[this->length];//길이 크기의 char 배열을 생성하여 
		for (int i = 0; i < this->length; i += 1)//for문으로 입력받은 문자열을 char 배열에 저장
		{
			this->characters[i] = str[i];
		}

	}
	
	MyString(const string& original)
	{
		
		this->length = original.length();//입력받은 변수의 길이를 this->length에 입력
		this->characters = new char[this->length]; //길이만큼 char 배열할당
		for (int i = 0; i < this->length; i += 1) //for문으로 입력받은 문자열을 배열에 저장
		{
			this->characters[i] = original[i];
		}
	}

	~MyString()//소멸자
	{
		delete[] characters;
	}


	/*
	o	비교할 문자열 (오른쪽 항)
	return true		this가 o보다 사전순으로 앞선다면 true
	return false	 반대
	*/

	/* 각 연산자에 대해 정의*/

	bool operator < (const MyString &o) const {// 연산자 < 의 경우 호출됨.
		int n = min(this->length, o.length);
		//this->length는 s1, o.length는 s2의 문자열의 길이를 비교하여 작은값을 n에 입력
		

		for (int i = 0; i < n; i++) { 
			//this가 o보다 사전순으로 앞선다면 True
			if (this->characters[i] < o.characters[i]) {
				
				return true;
			}
			//반대경우
			else if (this->characters[i] > o.characters[i]) {
				
				return false;
			}
		}
		//문자열이 일부 동일하여 반복문에서 아무 리턴값없이 벗어난 경우 처리 ex algorithm, algo
			if (this->length < o.length) { //첫번째 문자열의 길이가 더 짧다면 true 아니라면 false
				
				return true; 
			}
			else { 
				
				return false;
			}
		}
	
	/* o가 this보다 사전순으로 앞선다면 */

	bool operator > (const MyString &o) const { // 연산자 > 경우 
		int n = min(this->length, o.length); //문자열의 길이를 비교하여 작은값을 n에 입력

		for (int i = 0; i < n; i++) {
			if (this->characters[i] < o.characters[i]) {
				
				return false;//this가 o보다 사전순으로 앞선다면 false
			}
			else if (this->characters[i] > o.characters[i]) {
				
				return true;//o가 this보다 사전순으로 앞선다면 True
			}
		}
		//문자열이 일부 동일하여 반복문에서 아무 리턴값없이 벗어난 경우 처리
			if (this->length > o.length) { //첫번째 문자열의 길이가 더 길다면 true 아니라면 false
				;
				return true;
			}
			else {
				
				return false;
			}
		}

	
	/*두 문자열이 같다면 true 다르다면 false*/
	bool operator == (const MyString &o) const {
		
		if (this->length != o.length)  //길이가 다르다면 false
			
			return false;

		for (int i = 0; i < this->length; i++) { //길이는 같고 
			if (this->characters[i] != o.characters[i]) { //각 글자가 일치하지 않으면 false
				
				return false;
			}
		}
		
		return true; //두 문자열이 일치하므로 true
	}

};


int main()
{
	string s1; //첫 번째 문자열 입력받는 변수
	string s2; //두 번째 문자열 입력받는 변수
	cin >> s1 >> s2; //scanf 대신 추출연산자 >>

	MyString mys1(s1); //생성자 호출
	MyString mys2(s2); //생성자 호출

	if (mys1 < mys2) //첫 번째 문자열이 사전순으로 앞선다면 -1을 출력
	{
		printf("-1"); //= cout <<"-1"<<endl 삽입연산자 <<
	}
	else if (mys1 > mys2)//두 번째 문자열이 사전순으로 앞선다면 1을 출력
	{
		printf("1");
	}
	else { //두 문자열이 일치한다면 0을 출력
		printf("0");
	}

	return 0;
}