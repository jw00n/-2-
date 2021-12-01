#include<stdio.h>
#include<map>

using namespace std;

int main() {
	int N; //�Է����� �־��� ������ ���� N
	scanf("%d", &N); //�Է¹޴´�.

	//�� <����, �󵵼�> ���·� key/value=Ƚ���� ������ Map �ڷᱸ�� ������)
	//frequencyMap := ������ �Էµ� �������� �󵵼��� �����ϰ� �ִ�.
	map<int, int> frequencyMap;
	 
	for (int i = 0; i < N; i++) {
		int X; //N�� �ݺ��ϸ� 
		scanf("%d", &X); // ������ �� �� �� �Է¹޴´�.
		frequencyMap[X]++;//frequencyMap[key]-> key������ ã�� key�� �����ϴ� value������
		//key���� �Է¹��� ���� X�� �ְ� value(�󵵼�)�� 0���� �ʱ�ȭ�ƴٰ�  ++�� 1�� �����Ѵ�
		printf("%d %d\n", frequencyMap.size(), frequencyMap[X]); //frequencyMap.size() = ���� �� //frequencyMap[X]=�� ����
	}
	//�ߺ��� ���� ++�� Ƚ���� �����ȴ�.

	return 0;

	/*
	key�� ���� ����ϰ� ���� ���))) �� ��� key���� �������� ������������ ���´�. 

	map<int, int> :: iterator it;

	for(it = frequencyMap.begin(); it!= frequencyMap.end(); it++)
	{
	printf("%d %d\n", it->first, it->second); //first->key // second->Ƚ��  
	}
	*/
}