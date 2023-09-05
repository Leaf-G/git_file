//
// Created by gcc on 6/1/23.
//

#include <iostream>
#include <iomanip>

void show_mem_rep(char *start, int n) {
    for (int i = 0; i < n; ++i) {
//        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(start[i]) << std::endl;

//        printf("%.2x", start[i]);
        printf("\n");
    }

}

int main() {
    int i = 0x01234567;
    show_mem_rep((char *)&i, sizeof (i));
}