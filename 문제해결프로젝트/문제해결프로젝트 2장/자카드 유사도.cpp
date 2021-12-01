#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //transform�� ��������
#include<cctype> //�빮��<-> �ҹ��� 
#include<time.h>


using namespace std;

//���� ���ڿ�(�� ����)�� ���� �ε��� �������ִ� �Լ�
int getIndex(string a) {
    return ((int)a[0] - 65) * 28 + ((int)a[1] - 65);
}

int main() {


    string str1;//ù ��° ���ڿ�
    string str2;//�� ��° ���ڿ�

    //������ ����� ���� �ε����迭(���ĺ� 28*28)
    int idx1[784] = { 0 }; 
    int idx2[784] = { 0 };

    //�������� ���ڿ��� �Է¹ޱ����� getline�� ����Ѵ�.
    getline(cin, str1);
    getline(cin, str2);

//��������
    clock_t start = clock();

    //�񱳿��̸� ���Ͽ� str1,str2�� ��� ���ĺ��� �빮�ڷ� ��ȯ�Ѵ�.
    transform(str1.begin(), str1.end(), str1.begin(), toupper);
    transform(str2.begin(), str2.end(), str2.begin(), toupper);


    //���ڿ��� �� ���ھ� ��� ������ ����
    vector<string> twoChar1(str1.size());
    vector<string> twoChar2(str2.size());

    //������ ������ �ε����� �����ϱ� ���� ������ ���� ������ش�.
    int index1 = 0;
    int index2 = 0;


    //���ڿ� �� ���� ¦���� -> ¦ ����= ���ڼ� - 1
    for (int i = 0; i < (int)str1.size() - 1; i++) {
        string temp = str1.substr(i, 2);//i��°���� 2���ھ� �κй��ڿ� ����

        //�� ���� ��� ���ĺ��ϰ�쿡�� ����(�빮�ڷ� �ٲ㼭 �빮�� �����ȿ� ���⸸�ϸ� ok)
        if ((temp[0] >= 'A' && temp[0] <= 'Z') && ( temp[1] >= 'A' && temp[1] <= 'Z')) {
            twoChar1[index1] = temp; //���ǿ� �����ϸ� �ش� 2������ ���ڿ��� ���� twoChar1�� �������ش�.
            index1++;//����� ��쿡�� �ε����� 1�� ����
        }
        else 
        { //���� ũ�⸦ ���ڿ� ũ���� �Ҵ��صױ⶧���� ����,���� ���� �ٸ� ������ ��쿣��
            twoChar1.pop_back();//�� ���� �������ָ� ũ�⸦ ���δ�.
        }

    }


    for (int i = 0; i < (int)str2.size() - 1; i++) {
        string temp = str2.substr(i, 2);//i��°���� 2���ھ� �κй��ڿ� ����
                
        //�� ���� ��� ���ĺ��ϰ�쿡�� ����(�빮�ڷ� �ٲ㼭 �빮�� �����ȿ� ���⸸�ϸ� ok)
        if ((temp[0] >= 'A' && temp[0] <= 'Z') && (temp[1] >= 'A' && temp[1] <= 'Z')) {
            twoChar2[index2] = temp;//���ǿ� �����ϸ� �ش� 2������ ���ڿ��� ���� twoChar2�� �������ش�.
            index2++;//����� ��쿡�� �ε����� 1�� ����
        }
        else {
             //���� ũ�⸦ ���ڿ� ũ���� �Ҵ��صױ⶧���� ����,���� ���� �ٸ� ������ ��쿣 
            twoChar2.pop_back();//�� ���� �������ָ� ũ�⸦ ���δ�.
        }
    }


    /*
    �������� �� ������ ���� �� - �������̹Ƿ� ���� ���� �� �ִ�.
    
    *������
    - ���� �ε����� ���ϴ� ������� ���� ���̱� ������ ���ĺ� ���� ������ŭ�� �迭 �� ��(idx1, idx2)�� ������� ��
    - twoChar1,2�� �����ϴ� �� 2 ���� ���ڿ��� �ش��ϴ� �ε����� 1�� ������Ų��.
    - �ε��� ���� ��½��Ѽ�
    ex)�̿� ���� ���´ٸ�
               0  1  2  3  4  5
        idx1   1  2  1  1  0  1
        idx2   1  3  1  1  2  1
    ��������   1  2  1  1  0  1 �� �ּҰ��� ������ �������̶� �� �� �ִ�.

    */

    //���ڿ��� �ش��ϴ� �ε����� getindex�� ���ؿͼ� �ش� �ε��� 1 ����
    for (int i = 0; i < (int)twoChar1.size() - 1; i++) {
        idx1[getIndex(twoChar1[i])]++;
    }
    for (int i = 0; i < (int)twoChar2.size() - 1; i++) {
        idx2[getIndex(twoChar2[i])]++;
    }
  
   
    int flag_i = 0, flag_u = 0; //flag_i= ������ //flag_u=������
   
    //���ĺ� ������ ����� �� =28*28 =784���� �ݺ��ϸ�
    for (int i = 0; i < 784; i++) {
        if ((idx1[i]>=1) &&(idx2[i]>=1) ) //�� �� 1�̻�// ���� ���� 1���� �̻�
            flag_i += idx1[i] >= idx2[i] ? idx2[i] : idx1[i]; //idx1[i]�� idx2[i]���� ũ�ų� ���ٸ� idx2[i]�� ���� �����ش�. �۴ٸ� idx1[i] -> min�� ������
    }

    //������ //-2�� ����..
    flag_u = ((int)twoChar1.size() + (int)twoChar2.size() - 2 - flag_i);

   
    if (flag_u == 0) { //�� ������ �������ϰ�� => �������� ������ -> ���絵= 1
        cout << "1" << endl;
    }
    else {//��ī�� ���絵 ��� // ������ ǥ���ϱ����� *65536
        cout << flag_i * 65536 / flag_u << endl;
    }

    clock_t end = clock();; //���� ���� 
    printf("����ð�: %lf\n", (double)(end - start)/CLOCKS_PER_SEC); //�ð� �ʴ����� ���


    return 0;
}


