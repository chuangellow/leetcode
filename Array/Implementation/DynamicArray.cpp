#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(): arrSize(0), currentMaxSize(INIT_ARR_SIZE) {
    arr = (size_t*) (sizeof(size_t) * INIT_ARR_SIZE);
    for (int i = 0; i < INIT_ARR_SIZE; i++) {
        arr[i] = (size_t) 0;
    }
}

DynamicArray::~DynamicArray() {
    free(arr);
}

void DynamicArray::resize() {
    if (arrSize < currentMaxSize) return;
    ll newSize = 2 * currentMaxSize * sizeof(size_t);
    size_t* newArr = (size_t*) realloc(arr, newSize);
    if (newArr == nullptr) {
        std::cerr << "Fail to resize the array!!!" << std::endl;
        return;
    }
    else {
        arr = newArr;
        currentMaxSize *= 2;
    }
}