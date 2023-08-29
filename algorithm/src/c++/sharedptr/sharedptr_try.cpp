//
// Created by gcc on 6/21/23.
//
#include "sharedptr.h"
#include <memory>
#include <iostream>

int main() {
    int a1 = 3;
//    std::shared_ptr<>
    std::shared_ptr<int> a2(new int(10));
    SharedPtr<int> a(new int(10));
    std::cout << *a << std::endl;
}