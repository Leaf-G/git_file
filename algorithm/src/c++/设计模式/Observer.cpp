//
// Created by gcc on 7/13/23.
//
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Subject;
//观察者 基类 （内部实例化了被观察者的对象sub）
class Observer {
protected:
    string name;
    Subject *sub;
public:
    Observer(string name, Subject *sub) {
        this->name = name;
        this->sub = sub;
    }
    virtual void update() = 0;
};
class StockObserver : public Observer {
public:
    StockObserver(string name, Subject *sub) : Observer(name, sub){}
    void update();
};
class NBAObserver : public Observer {
public:
    NBAObserver(string name, Subject *sub) : Observer(name, sub){}
    void update();
};
//被观察者 基类 （内部存放了所有的观察者对象，以便状态发⽣变化时，给观察者发通知）
class Subject {
protected:
    std::list<Observer *> observers;
public:
    string action; //被观察者对象的状态
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};
class Secretary : public Subject {
    void attach(Observer *observer) {
        observers.push_back(observer);
    }
    void detach(Observer *observer) {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            if ((*iter) == observer) {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    void notify() {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end()) {
            (*iter)->update();
            ++iter;
        }
    }
};
void StockObserver::update() {
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "⽼板来了!") {
        cout << "我⻢上关闭股票，装做很认真⼯作的样⼦！" << endl;
    }
}
void NBAObserver::update() {
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "⽼板来了!") {
        cout << "我⻢上关闭 NBA，装做很认真⼯作的样⼦！" << endl;
    }
}
int main()
{
    Subject *BOSS = new Secretary();
    Observer *xa = new NBAObserver("xa", BOSS);
    Observer *xb = new NBAObserver("xb", BOSS);
    Observer *xc = new StockObserver("xc", BOSS);
    BOSS->attach(xa);
    BOSS->attach(xb);
    BOSS->attach(xc);
    BOSS->action = "去吃饭了！";
    BOSS->notify();
    cout << endl;
    BOSS->action = "⽼板来了!";
    BOSS->notify();
    return 0;
}
//输出
//product A create! product B create!