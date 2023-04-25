# c++

## *结构体内存对齐*

计算机系统对于基本数据类型数据在内存中存放要求他们的**首地址是某个数的倍数**。

- #pragma pack(n)

​		指定编译器的有效对齐值，且有效对齐值是**\#pragma pack(n)**和**结构体中最长数据类型**长度中**较小**的那个

- alignas 

  与#pragma pack(n)类似，制定结构体的对齐值，但alignas可使对齐值不受#pragma pack(n)影响。优先级最高。

- alignof

  计算出对齐值

- 结构体内成员按照声明顺序存储，第一个成员地址和整个结构体地址相同。
- 未特殊说明时，按结构体中size最大的成员对齐（若有double成员，按8字节对齐。）



参考文献：[C/C++内存对齐详解](https://zhuanlan.zhihu.com/p/30007037)

## 指针与引用

- 指针是一个变量，存储地址，引用只是变量别名=>
  - 指针可以多级，引用只能一级、
  - 指针可以为空（NULL），引用不能为空且定义必须初始化（引用只是别名，不初始化，就没有引用的原名）
  - 指针可以在初始化后改变指向，引用不行
  - sizeof得到的是指针的大小，sizeof引用得到所指变量大小
  - 函数中指针传递不改变原值，引用会

## 指针类型

```c++
int *p[10]      //指针数组
int (*p)[10]	//指向int数组的指针
int *p(int)		//函数声名，函数名为p，参数为int型，返回值为int*
int (*p)(int)	//函数指针，指向int型参数，返回值也是int型的函数
```

## C++中的构造函数

- 默认构造函数

- 初始化构造函数（有参数）

- 拷贝构造函数

- 移动构造函数（move和右值引用）

- 委托构造函数

- 转换构造函数

- ```c++
  #include <iostream>
  using namespace std;
  
  class Student{
  public:
      Student(){//默认构造函数，没有参数
          this->age = 20;
          this->num = 1000;
      };  
      Student(int a, int n):age(a), num(n){}; //初始化构造函数，有参数和参数列表
      Student(const Student& s){//拷贝构造函数，这里与编译器生成的一致
          this->age = s.age;
          this->num = s.num;
      }; 
      Student(int r){   //转换构造函数,形参是其他类型变量，且只有一个形参
          this->age = r;
  		this->num = 1002;
      };
      ~Student(){}
  public:
      int age;
      int num;
  };
  
  int main(){
      Student s1;
      Student s2(18,1001);
      int a = 10;
      Student s3(a);
      Student s4(s3);
      
      printf("s1 age:%d, num:%d\n", s1.age, s1.num);
      printf("s2 age:%d, num:%d\n", s2.age, s2.num);
      printf("s3 age:%d, num:%d\n", s3.age, s3.num);
      printf("s2 age:%d, num:%d\n", s4.age, s4.num);
      return 0;
  }
  //运行结果
  //s1 age:20, num:1000
  //s2 age:18, num:1001
  //s3 age:10, num:1002
  //s2 age:10, num:1002
  
  ```

  