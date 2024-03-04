#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int budget = 0;
int totalCost = 0;
int arrSize = 0;

int findMin(int startIndex, int *nums) {
    int minIndex = startIndex;
    int min = nums[startIndex];
    for (int i = startIndex + 1; i < arrSize; i++) {
        if (nums[i] >= min) continue;
        min = nums[i];
        minIndex = i;
    }
    return minIndex;
}

void selectionSort(int *nums) {
    for (int i = 0; i < arrSize - 1; i++) {
        int minIndex = findMin(i, nums);
        if (minIndex != i) {
            swap(&nums[minIndex], &nums[i]);
            totalCost++;
        }
        if (totalCost >= budget) return;
    }
    return;
}

int main(void) {
    scanf("%d%d", &arrSize, &budget);
    int *nums = (int *) calloc(arrSize, sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Fail to malloc!!!");
        exit(1);
    }
    for (int i = 0; i < arrSize; i++) scanf("%d", &nums[i]);
    selectionSort(nums);
    printArr(nums, arrSize, totalCost);
    free(nums);
    return 0;
}