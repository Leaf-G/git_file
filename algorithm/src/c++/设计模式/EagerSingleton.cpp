#include <iostream>
#include <algorithm>

using namespace std;

class EagerSingleton {
public:
    static EagerSingleton GetInstance() {
        return ins;
    }
    ~EagerSingleton(){};
private:
    //涉及到创建对象的函数都设置为private
    EagerSingleton() { std::cout<<"EagerSingleton() 饿汉"<<std::endl; }
    EagerSingleton(const EagerSingleton& other) {};
    EagerSingleton& operator=(const EagerSingleton& other) {return *this;}

    static EagerSingleton ins;
};

// 初始化静态成员变量
EagerSingleton EagerSingleton::ins = EagerSingleton();

int main(){
    std::cout << "Main function started." << std::endl;
    //因为不能创建对象所以通过静态成员函数的⽅法返回静态成员变ᰁ
    EagerSingleton ins = EagerSingleton::GetInstance();
    std::cout << "Main function started." << std::endl;
    return 0;
}
//输出 EagerSingleton() 饿汉