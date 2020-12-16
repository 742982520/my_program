#include <iostream>
#include <string>
using namespace std;
//����cpu��
class CPU{
public:
    virtual void calculate() = 0;
};
//�����Կ���
class GPU{
public:
    virtual void graphics() = 0;
};
//�����ڴ���
class Memory{
public:
    virtual void memory() = 0;
};
//��װ������
class Computer{
private:
    CPU* m_cpu;
    GPU* m_gpu;
    Memory* m_memory;
public:
    //�ڴ��������ʱ��ʵ���˸���ָ��ָ���������
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
//����CPU����
class IntelCPU : public CPU{
public:
    virtual void calculate(){
        cout<<"intel��cpu�Ѿ���ʼ����"<<endl;
    }
};
class IntelGPU : public GPU{
public:
    virtual void graphics(){
        cout<<"intel��gpu�Ѿ���ʼ������"<<endl;
    }
};
class IntelMemory : public Memory{
public:
    virtual void memory(){
        cout<<"intel��memory�Ѿ���ʼ������"<<endl;
    }
};
void test(){
    //��װ��һ̨����
    cout<<"===========��װ��һ̨����=========="<<endl;
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
