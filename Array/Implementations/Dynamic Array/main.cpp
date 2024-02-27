#include <iostream>
#include "DynamicArray.h"

int main(void) {
    DynamicArray arr;
    for (int i = 0; i < INIT_ARR_SIZE; i++) {
        arr[i] = i;
    }
    arr[INIT_ARR_SIZE+1] = INIT_ARR_SIZE + 1;
    std::cout << arr[INIT_ARR_SIZE+1] << std::endl;
    std::cout << "Size: " << arr.size() << std::endl;
    return 0;
}