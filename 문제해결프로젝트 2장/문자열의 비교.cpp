#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_LENGTH = 100000; //�ִ���̴� 10�� ����

class MyString {
private:
	char* characters; //���ڿ�
	int length; //���ڿ��� ����

public:
	
	MyString(const char* str)
	{//����ü ����, ���ڿ�
	
		this->length = strnlen(str, MAX_LENGTH); //strnlen���� ���� �ľ�, �ִ���̸� ������ �ִ���̰� ���ϵ�.
		this->characters = new char[this->length];//���� ũ���� char �迭�� �����Ͽ� 
		for (int i = 0; i < this->length; i += 1)//for������ �Է¹��� ���ڿ��� char �迭�� ����
		{
			this->characters[i] = str[i];
		}

	}
	
	MyString(const string& original)
	{
		
		this->length = original.length();//�Է¹��� ������ ���̸� this->length�� �Է�
		this->characters = new char[this->length]; //���̸�ŭ char �迭�Ҵ�
		for (int i = 0; i < this->length; i += 1) //for������ �Է¹��� ���ڿ��� �迭�� ����
		{
			this->characters[i] = original[i];
		}
	}

	~MyString()//�Ҹ���
	{
		delete[] characters;
	}


	/*
	o	���� ���ڿ� (������ ��)
	return true		this�� o���� ���������� �ռ��ٸ� true
	return false	 �ݴ�
	*/

	/* �� �����ڿ� ���� ����*/

	bool operator < (const MyString &o) const {// ������ < �� ��� ȣ���.
		int n = min(this->length, o.length);
		//this->length�� s1, o.length�� s2�� ���ڿ��� ���̸� ���Ͽ� �������� n�� �Է�
		

		for (int i = 0; i < n; i++) { 
			//this�� o���� ���������� �ռ��ٸ� True
			if (this->characters[i] < o.characters[i]) {
				
				return true;
			}
			//�ݴ���
			else if (this->characters[i] > o.characters[i]) {
				
				return false;
			}
		}
		//���ڿ��� �Ϻ� �����Ͽ� �ݺ������� �ƹ� ���ϰ����� ��� ��� ó�� ex algorithm, algo
			if (this->length < o.length) { //ù��° ���ڿ��� ���̰� �� ª�ٸ� true �ƴ϶�� false
				
				return true; 
			}
			else { 
				
				return false;
			}
		}
	
	/* o�� this���� ���������� �ռ��ٸ� */

	bool operator > (const MyString &o) const { // ������ > ��� 
		int n = min(this->length, o.length); //���ڿ��� ���̸� ���Ͽ� �������� n�� �Է�

		for (int i = 0; i < n; i++) {
			if (this->characters[i] < o.characters[i]) {
				
				return false;//this�� o���� ���������� �ռ��ٸ� false
			}
			else if (this->characters[i] > o.characters[i]) {
				
				return true;//o�� this���� ���������� �ռ��ٸ� True
			}
		}
		//���ڿ��� �Ϻ� �����Ͽ� �ݺ������� �ƹ� ���ϰ����� ��� ��� ó��
			if (this->length > o.length) { //ù��° ���ڿ��� ���̰� �� ��ٸ� true �ƴ϶�� false
				;
				return true;
			}
			else {
				
				return false;
			}
		}

	
	/*�� ���ڿ��� ���ٸ� true �ٸ��ٸ� false*/
	bool operator == (const MyString &o) const {
		
		if (this->length != o.length)  //���̰� �ٸ��ٸ� false
			
			return false;

		for (int i = 0; i < this->length; i++) { //���̴� ���� 
			if (this->characters[i] != o.characters[i]) { //�� ���ڰ� ��ġ���� ������ false
				
				return false;
			}
		}
		
		return true; //�� ���ڿ��� ��ġ�ϹǷ� true
	}

};


int main()
{
	string s1; //ù ��° ���ڿ� �Է¹޴� ����
	string s2; //�� ��° ���ڿ� �Է¹޴� ����
	cin >> s1 >> s2; //scanf ��� ���⿬���� >>

	MyString mys1(s1); //������ ȣ��
	MyString mys2(s2); //������ ȣ��

	if (mys1 < mys2) //ù ��° ���ڿ��� ���������� �ռ��ٸ� -1�� ���
	{
		printf("-1"); //= cout <<"-1"<<endl ���Կ����� <<
	}
	else if (mys1 > mys2)//�� ��° ���ڿ��� ���������� �ռ��ٸ� 1�� ���
	{
		printf("1");
	}
	else { //�� ���ڿ��� ��ġ�Ѵٸ� 0�� ���
		printf("0");
	}

	return 0;
}