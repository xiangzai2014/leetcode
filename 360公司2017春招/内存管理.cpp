/*
题目描述

物联网技术的蓬勃发展，各种传感器纷纷出现。小B所在的项目组正在开发一个物联网项目，她们在研究设计一种新的传感器。这种传感器有自己的基本处理单元，
具有一定的自主性，能够进行简单的数据收集、处理、存储和传输。为降低系统功耗并保证系统可靠性和可控性，他们要对内存进行基本的管理。研究小组计划开发一个实验性内存管理器，
实现对内存的分配、释放和整理。对应的接口为new、del和def，使用语法为：
new size：分配size字节大小的内存块，返回该内存块的句柄handle，size为正整数；
del handle：释放句柄handle指向的内存块；
def：整理内存碎片，将所有已分配内存块按地址从低到高的顺序迁移，使空闲内存碎片在高地址端拼接在一起；
初始内存为 initSize 字节大小的整片空闲内存，编号为 1 到 initSize 。
new size操作中，若存在不小于size的连续空闲内存，则按照小地址优先的原则从空闲内存区域中分配size大小的内存块，标记该内存块状态为已分配，并返回指向该内存块的句柄。若无法分配，则返回空（NULL）。
del handle操作释放由handle标记的内存块，标记被释放的内存状态为空闲。若handle为无效句柄，则返回ILLEGAL_OPERATION。
def 完成内存整理工作，无返回值。
根据设计，每次成功内存分配返回的句柄为一个正整数，从1开始，依次计数。失败的存储分配操作不影响计数。
项目小组将此项任务分配给小B，小B向你求助，你能帮她吗？
输入
输入中有多组测试数据。每组测试数据的第一行为两个正整数T和MaxMem（1<=T<=10000, 1<=MaxMem<=10000），其中T为操作次数，MaxMem为初始内存大小，随后有T行操作指令。
输出
对每组测试数据，按操作顺序输出操作结果。对每个new操作，在单独行中输出结果，成功时输出其返回句柄值，失败则输出NULL。若del操作失败，输出ILLEGAL_OPERATION。def不产生输出。
样例输入
6 10
new 5
new 3
del 1
new 6
def
new 6
样例输出
1
2
NULL
3
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class memManage{
private:
    int maxBlock;
    map<int, int> location;
    int handle;
    vector<int> memory;

public:
    int maxMem;
    memManage(int m):maxMem(m){
        handle = 0;
        maxBlock = maxMem;
        memory.resize(maxMem, 0);
        location[0] = maxMem;
    }

public:
    void New(int memSize){
        if(memSize > maxBlock){
            cout << "NULL" << endl;
        }
        else{
            cout << ++handle << endl;
            int start = 0;
            for(map<int, int>::iterator it = location.begin(); it != location.end(); it ++){
                if(it->second >= memSize){
                    start = it->first;
                    break;
                }
            }
            for(int i = 0; i < memSize; i ++){
                memory[start+i] = handle;
            }
            updateBlock();
        }
    }

    void DEF(){
        vector<int> temp(memory);
        memory.clear();
        memory.resize(maxMem, 0);
        int j = 0;
        for(int i = 0; i < maxMem; i ++){
            if(temp[i] != 0){
                memory[j++] = temp[i];
            }
        }
        updateBlock();
    }

    void DEL(int memHandle){
        if(memHandle < 1 || find(memory.begin(), memory.end(), memHandle) == memory.end()){//若handle为无效句柄
            cout<<"ILLEGAL_OPERATION"<<endl;
        }else{
            for(int i = 0; i < maxMem; i ++){
                if(memory[i] == memHandle){
                    memory[i] = 0;
                }
            }
            updateBlock();
        }
    }

private:
    void updateBlock(){//更新空闲块
        location.clear();
        for(int i = 0; i < maxMem; i ++){
            int count = 0;
            while(i < maxMem && memory[i] == 0){
                count ++;
                i ++;
            }
            if(count != 0){
                location[i-count] = count;
            }
            int maximum = 0;
            for(map<int, int>::iterator it = location.begin(); it != location.end(); it ++){
                maximum = max(maximum, it->second);
            }
            maxBlock = maximum;//最大内存块
        }
    }
};

int main(){
    int T, MaxMem;
    string op;
    int n;
    while(cin >> T >> MaxMem){
        memManage solution(MaxMem);
        for(int i = 0; i < T; i ++){
            cin >> op;
            if(!op.compare("new")){
                cin >> n;
                solution.New(n);
            }
            if(!op.compare("del")){
                cin >> n;
                solution.DEL(n);
            }
            if(!op.compare("def")){
                solution.DEF();
            }
        }
    }
    return 0;
}
