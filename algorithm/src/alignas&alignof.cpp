//
// Created by gcc on 4/24/23.
//

//更改有效对齐值
#pragma pack(1)

// alignas 生效的情况
#include <iostream>

struct Info {
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

//alignas设置对齐值不受#pragma pack(1)影响，对齐值依旧为4
struct alignas(4) Info2 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};


int main() {
    std::cout << sizeof(Info) << std::endl;   // 6  2 + 2 + 2
    std::cout << alignof(Info) << std::endl;  // 2


    std::cout << sizeof(Info2) << std::endl;   // 8  4 + 4
    std::cout << alignof(Info2) << std::endl;  // 4
}