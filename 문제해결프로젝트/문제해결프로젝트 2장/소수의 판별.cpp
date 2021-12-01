#include<cstdio>
#include<iostream>

using namespace std;

/*
�־��� ���ڰ� �Ҽ����� �Ǻ��ϴ� �Լ�

�Ҽ� - ����� 1�� �ڽŻ�
N
return true �Ҽ����
return false �Ҽ��� �ƴ϶��
*/

bool isPrime(int N)
{
	if (N == 1) return false; //1�� ��� 1���̹Ƿ� �Ҽ� �ƴϹǷ� false ����

	//int cnt = 0; //��� ���� ī��Ʈ�ϴ� ����
	for (int i = 2;i * i <= N; i++) 
		//�ݺ���,1�� ������ ������ 2���� ���� 
		// 2~N���� �ݺ��ϴ°� �ƴ� 2~��ƮN���� �ϴ� ������ ����� ���� �̷�� �����̴�.
		//axb= N�϶� a�� <=��ƮN�ϼ��ۿ� �����Ƿ� �߹ݱ����� �˻��ϴ� ������ε� �ð����⵵�� O(n) -> O(n^ 1/2)�� ���ҽ�ų�� �ִ�. ǥ���� i*i <=N ����
	{
		if (N % i == 0) //N�� 10������Ƿ� �ݺ����� 10��� �ݺ��ϹǷ� ���� �ʿ䰡 �ִ�.  
			//cnt++; ����� ���翩�θ� �Ǵ��ϸ� �ǹǷ� cnt �ʿ����
			return false; //�Ҽ��� ����� ������ �ȵǹǷ� false
	}
	return true; //�ݺ������� ����ٸ� true ����
}

void testcase(int caseIndex)
{
	int n; //�Ҽ����� �Ǵ��ؾ��ϴ� ���ڸ�
	scanf("%d", &n);//�Է¹���

	bool result = isPrime(n); //�Ҽ� �Ǵ��Լ� ȣ�� 

	printf("Case #%d\n", caseIndex); //�׽�Ʈ ���̽��� ��ȣ(caseIndex) ���
	if (result) //����� 
	{
		printf("Yes\n");//true�� yes, 
	}
	else { //�ƴϸ� no
		printf("No\n");
	}
}


int main()
{
	int caseSize; //�׽�Ʈ ���̽� ���� 
	scanf("%d", &caseSize); //�Է� ����
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) 
	{
		testcase(caseIndex); //�׽�Ʈ ���̽� �Լ� ����
	}

	return 0;
}