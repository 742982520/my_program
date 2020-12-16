#include <iostream>
#include <string>
using namespace std;
//抽象cpu类
class CPU{
public:
    virtual void calculate() = 0;
};
//抽象显卡类
class GPU{
public:
    virtual void graphics() = 0;
};
//抽象内存类
class Memory{
public:
    virtual void memory() = 0;
};
//组装电脑类
class Computer{
private:
    CPU* m_cpu;
    GPU* m_gpu;
    Memory* m_memory;
public:
    //在传入参数的时候，实现了父类指针指向子类对象
    Computer(CPU* cpu, GPU* gpu, Memory* memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    void build_up(){
        m_cpu->calculate();
        m_gpu->graphics();
        m_memory->memory();
    }
    ~Computer(){
    }
};
//具体CPU厂商
class IntelCPU : public CPU{
public:
    virtual void calculate(){
        cout<<"intel的cpu已经开始工作"<<endl;
    }
};
class IntelGPU : public GPU{
public:
    virtual void graphics(){
        cout<<"intel的gpu已经开始工作了"<<endl;
    }
};
class IntelMemory : public Memory{
public:
    virtual void memory(){
        cout<<"intel的memory已经开始工作了"<<endl;
    }
};
void test(){
    //组装第一台电脑
    cout<<"===========组装第一台电脑=========="<<endl;
    IntelCPU intel_cpu;
    IntelGPU intel_gpu;
    IntelMemory intel_memory;
    Computer *computer= new Computer(&intel_cpu, &intel_gpu, &intel_memory);
    computer->build_up();
    delete computer;
    computer = NULL;
}
int main(){
    test();
    system("pause");
    return 0;
}
