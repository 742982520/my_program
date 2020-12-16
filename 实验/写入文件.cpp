#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void test(){
    //创建输出流对象
    ofstream ofs;
    //指定打开文件的路径和打开的方式
    ofs.open("test.txt",ios::out);
    //写入内容
    ofs<<"hello world"<<endl;
    //关闭文件
    ofs.close();
}
int main(){
    test();
    system("pause");
    return 0;
}
