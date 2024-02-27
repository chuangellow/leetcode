#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"

DynamicArray::DynamicArray(): arrSize(INIT_ARR_SIZE) {
    arr = (size_t*) malloc(sizeof(size_t) * INIT_ARR_SIZE);
    for (int i = 0; i < INIT_ARR_SIZE; i++) {
        arr[i] = (size_t) 0;
    }
}

DynamicArray::~DynamicArray() {
    free(arr);
}

int DynamicArray::resize() {
    ll newSize = 2 * arrSize * sizeof(size_t);
    size_t* newArr = (size_t*) realloc(arr, newSize);
    if (newArr == nullptr) {
        std::cerr << "Fail to resize the array!!!" << std::endl;
        return -1;
    }
    else {
        arr = newArr;
        arrSize *= 2;
        for (int i = arrSize >> 2; i < arrSize; i++) {
            arr[i] = 0;
        }
        return 0;
    }
}

size_t& DynamicArray::operator[](int index) {
    if (index >= arrSize) {
        resize();
    }
    if (index < 0 || index >= arrSize) {
        throw std::out_of_range("Index out of range!!!");
    }
    else {
        return arr[index];
    }
}