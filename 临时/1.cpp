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
    //创建输入流文件
    ifstream ifs;
    //打开文件,判断打开文件是否成功
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
