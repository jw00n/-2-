#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //transform을 쓰기위해
#include<cctype> //대문자<-> 소문자 
#include<time.h>


using namespace std;

//받은 문자열(두 글자)에 대한 인덱스 리턴해주는 함수
int getIndex(string a) {
    return ((int)a[0] - 65) * 28 + ((int)a[1] - 65);
}

int main() {


    string str1;//첫 번째 문자열
    string str2;//두 번째 문자열

    //교집합 계산을 위한 인덱스배열(알파벳 28*28)
    int idx1[784] = { 0 }; 
    int idx2[784] = { 0 };

    //공백포함 문자열을 입력받기위해 getline을 사용한다.
    getline(cin, str1);
    getline(cin, str2);

//측정시작
    clock_t start = clock();

    //비교용이를 위하여 str1,str2의 모든 알파벳을 대문자로 변환한다.
    transform(str1.begin(), str1.end(), str1.begin(), toupper);
    transform(str2.begin(), str2.end(), str2.begin(), toupper);


    //문자열을 두 글자씩 끊어서 저장할 벡터
    vector<string> twoChar1(str1.size());
    vector<string> twoChar2(str2.size());

    //저장할 벡터의 인덱스는 따로하기 위해 변수를 따로 만들어준다.
    int index1 = 0;
    int index2 = 0;


    //문자열 두 개씩 짝짓기 -> 짝 개수= 글자수 - 1
    for (int i = 0; i < (int)str1.size() - 1; i++) {
        string temp = str1.substr(i, 2);//i번째부터 2글자씩 부분문자열 추출

        //두 글자 모두 알파벳일경우에만 저장(대문자로 바꿔서 대문자 범위안에 들어가기만하면 ok)
        if ((temp[0] >= 'A' && temp[0] <= 'Z') && ( temp[1] >= 'A' && temp[1] <= 'Z')) {
            twoChar1[index1] = temp; //조건에 부합하면 해당 2글자의 문자열을 벡터 twoChar1에 저장해준다.
            index1++;//저장된 경우에만 인덱스를 1씩 증가
        }
        else 
        { //벡터 크기를 문자열 크기대로 할당해뒀기때문에 공백,숫자 등의 다른 글자일 경우엔는
            twoChar1.pop_back();//맨 끝을 삭제해주며 크기를 줄인다.
        }

    }


    for (int i = 0; i < (int)str2.size() - 1; i++) {
        string temp = str2.substr(i, 2);//i번째부터 2글자씩 부분문자열 추출
                
        //두 글자 모두 알파벳일경우에만 저장(대문자로 바꿔서 대문자 범위안에 들어가기만하면 ok)
        if ((temp[0] >= 'A' && temp[0] <= 'Z') && (temp[1] >= 'A' && temp[1] <= 'Z')) {
            twoChar2[index2] = temp;//조건에 부합하면 해당 2글자의 문자열을 벡터 twoChar2에 저장해준다.
            index2++;//저장된 경우에만 인덱스를 1씩 증가
        }
        else {
             //벡터 크기를 문자열 크기대로 할당해뒀기때문에 공백,숫자 등의 다른 글자일 경우엔 
            twoChar2.pop_back();//맨 끝을 삭제해주며 크기를 줄인다.
        }
    }


    /*
    합집합은 두 집합의 개수 합 - 교집합이므로 쉽게 구할 수 있다.
    
    *교집합
    - 먼저 인덱스를 비교하는 방법으로 구할 것이기 때문에 알파벳 조합 개수만큼의 배열 두 개(idx1, idx2)를 만들어준 후
    - twoChar1,2에 존재하는 각 2 글자 문자열에 해당하는 인덱스를 1씩 증가시킨다.
    - 인덱스 값을 상승시켜서
    ex)이와 같이 나온다면
               0  1  2  3  4  5
        idx1   1  2  1  1  0  1
        idx2   1  3  1  1  2  1
    교집합은   1  2  1  1  0  1 로 최소값이 각각의 교집합이라 할 수 있다.

    */

    //문자열에 해당하는 인덱스를 getindex로 구해와서 해당 인덱스 1 증가
    for (int i = 0; i < (int)twoChar1.size() - 1; i++) {
        idx1[getIndex(twoChar1[i])]++;
    }
    for (int i = 0; i < (int)twoChar2.size() - 1; i++) {
        idx2[getIndex(twoChar2[i])]++;
    }
  
   
    int flag_i = 0, flag_u = 0; //flag_i= 교집합 //flag_u=합집합
   
    //알파벳 조합의 경우의 수 =28*28 =784까지 반복하며
    for (int i = 0; i < 784; i++) {
        if ((idx1[i]>=1) &&(idx2[i]>=1) ) //둘 다 1이상// 각각 등장 1번씩 이상
            flag_i += idx1[i] >= idx2[i] ? idx2[i] : idx1[i]; //idx1[i]가 idx2[i]보다 크거나 같다면 idx2[i]의 값을 더해준다. 작다면 idx1[i] -> min이 교집합
    }

    //합집합 //-2는 보정..
    flag_u = ((int)twoChar1.size() + (int)twoChar2.size() - 2 - flag_i);

   
    if (flag_u == 0) { //두 집합이 공집합일경우 => 합집합이 공집합 -> 유사도= 1
        cout << "1" << endl;
    }
    else {//자카르 유사도 계산 // 정수로 표현하기위해 *65536
        cout << flag_i * 65536 / flag_u << endl;
    }

    clock_t end = clock();; //측정 종료 
    printf("실행시간: %lf\n", (double)(end - start)/CLOCKS_PER_SEC); //시간 초단위로 출력


    return 0;
}


