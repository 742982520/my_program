#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct person{
public:
    char m_name[64];
    int m_age;
};
void test(){
    //�����������ļ�
    ifstream ifs;
    //���ļ�,�жϴ��ļ��Ƿ�ɹ�
    ifs.open("test.txt",ios::in);

    string buf;
    int num;
    while(ifs>>buf&&ifs>>buf)
    {
        num++;
    }
    cout << num <<endl;
}
int main(){
    test();
    system("pause");
    return 0;
}
