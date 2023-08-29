//
// Created by gcc on 8/21/23.
//
#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass()" << endl;
    }

    ~MyClass()
    {
        cout << "~MyClass()" << endl;
    }

private:

};

int main()
{
    shared_ptr<MyClass> myclass_ptr(new MyClass);
    cout << "myclass_ptr.use_count: " << myclass_ptr.use_count() << endl;

    //创建空 weak_ptr
    weak_ptr<MyClass> w;

    //与 shared_ptr 指向相同的对象，shared_ptr 引用计数不变
    weak_ptr<MyClass> w2(myclass_ptr);
    cout << "w2.use_count: " << w2.use_count() << endl;

    //赋值后 w 与 myclass_ptr 共享对象
    w = myclass_ptr;
    cout << "myclass_ptr.use_count: " << myclass_ptr.use_count() << " w.use_count: " << w.use_count() << endl;

    //将 w 置空
    w.reset();
    cout << "myclass_ptr.use_count after w.reset: " << myclass_ptr.use_count() << " w.use_count: " << w.use_count() << endl;

    //w.expired(): 若 w.use_count() 为 0，返回 true，否则返回 false
    //w.lock(): 如果 expired() 为 true，返回一个空 shared_ptr，否则返回非空 shared_ptr
    shared_ptr<MyClass> p = w.lock();
    cout << " w.expired:  " << w.expired() << " w.lock: " << p << endl;

    w = w2;
    p = w.lock();
    cout << " w.expired:  " << w.expired() << " w.lock: " << p << endl;

    return 0;
}