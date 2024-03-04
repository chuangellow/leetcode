#include <stdio.h>
#include <stdlib.h>

void printArr(int *nums, int arrSize, int totalCost) {
    printf("After sorting, the arr is: ");
    for (int i = 0; i < arrSize; i++) {
        printf((i == arrSize-1)? "%d\n": "%d ", nums[i]);
    }
    printf("The cost of sorting is: %d\n", totalCost);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}