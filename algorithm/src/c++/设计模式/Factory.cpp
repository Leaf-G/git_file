//
// Created by gcc on 7/13/23.
//
#include <iostream>
#include <pthread.h>
using namespace std;
//产品类（抽象类，不能实例化）
class Product{
public:
    Product(){}
    virtual void show()=0; //纯虚函数
};
class Factory{//抽象类
public:
    virtual Product* CreateProduct()=0;//纯虚函数
};
//产品A
class ProductA:public Product{
public:
    ProductA(){}
    void show(){ std::cout<<"product A create!"<<std::endl; };
};
//产品B
class ProductB:public Product{
public:
    ProductB(){}
    void show(){ std::cout<<"product B create!"<<std::endl; };
};
//⼯⼚类A，只⽣产A产品
class FactorA: public Factory{
public:
    Product* CreateProduct(){
        Product* product_ = nullptr;
        product_ = new ProductA();
        return product_;
    }
};
//⼯⼚类B，只⽣产B产品
class FactorB: public Factory{
public:
    Product* CreateProduct(){
        Product* product_ = nullptr;
        product_ = new ProductB();
        return product_;
    }
};
int main(){
    Product* product_;
    auto MyFactoryA = new FactorA();
    product_ = MyFactoryA->CreateProduct();// 调⽤产品A的⼯⼚来⽣产A产品
    product_->show();
    delete product_;
    auto MyFactoryB=new FactorB();
    product_ = MyFactoryB->CreateProduct();// 调⽤产品B的⼯⼚来⽣产B产品
    product_->show();
    delete product_;
    return 0;
}
//输出
//product A create! product B create!