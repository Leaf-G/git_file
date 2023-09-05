//
// Created by gcc on 6/21/23.
//
#include <iostream>
#include <vector>
#include <deque>
#include "output_container.h"

template<class T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void BubbleSort(std::vector<T> &nums, int n){
    if (n <= 1)
        return;
    bool is_swap;
    for (int i = 1; i < nums.size(); ++i) {
        is_swap = false;
        for (int j = 1; j < nums.size() - i +1; ++j) {
            if (nums[j] < nums[j - 1]) {
                std::swap(nums[j], nums[j - 1]);
                is_swap = true;
            }
        }
        if (!is_swap) break;
    }
}

//void BubbleSort(std::vector<int> &nums, int n) {
//    if (n <= 1) return;
//    bool is_swap;
//    for (int i = 1; i < n; ++i) {
//        is_swap = false;
//        //设定⼀个标记，若为false，则表示此次循环没有进⾏交换，也就是待排序列已经有序，排序已经完成。
//        for (int j = 1; j < n - i + 1; ++j) {
//            if (nums[j] < nums[j-1]) {
//                std::swap(nums[j], nums[j-1]);
//                is_swap = true;//表示有数据交换
//            }
//        }
//        if (!is_swap) break;//没有数据交集，提前退出
//    }
//}

void InsertSort(std::vector<int> &nums,int n) {
    if (n <= 1) return;
    for(int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums [j-1]; --j) {
            std::swap(nums[j],nums[j-1]);
        }
    }
}

void SelectSort(std::vector<int> &nums, int n) {
    if (n <= 1) return;
    int mid;
    for (int i = 0; i < n - 1; ++i) {
        mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        std::swap(nums[mid],nums[i]);
    }
}

void QuickSort_edit(std::vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int first = l, last = r , key =nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) last--;
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) first++;
        nums[last] = nums[first];
    }
    nums[first] = key;
    QuickSort_edit(nums, l, first);
    QuickSort_edit(nums, first + 1, r);
}

void QuickSort(std::vector<int> &nums,int l,int r) {
    if (l + 1 >= r) return;
    int first = l, last = r - 1 ,key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) last--;//右指针 从右向左扫描 将⼩于piv的放到左边
                nums[first] = nums[last];
        while (first < last && nums[first] <= key) first++;//左指针 从左向右扫描 将⼤于piv的放到右边
                nums[last] = nums[first];
    }
    nums[first] = key;//更新piv
    QuickSort(nums, l, first);//递归排序 //以L为中间值，分左右两部分递归调⽤
    QuickSort(nums, first + 1, r);
}

int main() {
    std::vector<int> a = {34,66,2,5,95,4,46,27};
    std::deque<int> b = {34,66,2,5,95,4,46,27};
    b.emplace_back(4);
    b.emplace_front(3);
    b.emplace_front(32);
    QuickSort_edit(a, 0, a.size()-1); //cout => 2 4 5 27 34 46 66 95
//    a.erase(a.begin(), a.begin()+1);
//    std::cout << *a.begin() << std::endl;
//    std::cout << *a.end() << std::endl;
//    std::cout << a.at(3) << std::endl;
//    std::cout << b << std::endl;
    std::cout << a << std::endl;
    return 0;
}