#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void test(){
    //�������������
    ofstream ofs;
    //ָ�����ļ���·���ʹ򿪵ķ�ʽ
    ofs.open("test.txt",ios::out);
    //д������
    ofs<<"hello world"<<endl;
    //�ر��ļ�
    ofs.close();
}
int main(){
    test();
    system("pause");
    return 0;
}
