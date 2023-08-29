#include <pthread.h>
#include <iostream>
#include <algorithm>
using namespace std;
class LazySingleton {
public:
    static LazySingleton* GetInstance() {
        if (ins == nullptr) {
            pthread_mutex_lock(&mutex);
            if (ins == nullptr) {
                ins = new LazySingleton();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }
    ~LazySingleton(){};
    //互斥锁
    static pthread_mutex_t mutex;
private:
    //涉及到创建对象的函数都设置为private
    LazySingleton() { std::cout<<"LazySingleton() 懒汉"<<std::endl; }
    LazySingleton(const LazySingleton& other) {};
    LazySingleton& operator=(const LazySingleton& other) { return *this; }
    //静态成员
    static LazySingleton* ins;
};
//懒汉式 静态变ᰁ需要定义
LazySingleton* LazySingleton::ins = nullptr;
pthread_mutex_t LazySingleton::mutex;
int main(){
    std::cout << "Main function started." << std::endl;
    //因为不能创建对象所以通过静态成员函数的⽅法返回静态成员变ᰁ
    LazySingleton* ins = LazySingleton::GetInstance();
    delete ins;
    std::cout << "Main function started." << std::endl;
    return 0;
}
//输出 LazySingleton() 懒汉