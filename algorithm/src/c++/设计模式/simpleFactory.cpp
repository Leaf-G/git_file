//
// Created by gcc on 7/13/23.
//
#include <iostream>
#include <pthread.h>
using namespace std;
//产品类（抽象类，不能实例化）
class Product{
public:
    Product(){};
    virtual void show()=0; //纯虚函数
};
class productA : public Product{
public:
    productA(){};
    void show(){ std::cout << "product A create!" << std::endl; };
    ~productA(){};
};
class productB : public Product{
public:
    productB(){};
    void show(){ std::cout << "product B create!" << std::endl; };
    ~productB(){};
};
class simpleFactory{ // ⼯⼚类
public:
    simpleFactory(){};
    Product* product(const string str){
        if (str == "productA")
            return new productA();
        if (str == "productB")
            return new productB();
        return NULL;
    };
};
int main(){
    simpleFactory obj; // 创建⼯⼚
    Product* pro; // 创建产品
    pro = obj.product("productA");
    pro->show(); // product A create!
    delete pro;
    pro = obj.product("productB");
    pro->show(); // product B create!
    delete pro;
    return 0;
}