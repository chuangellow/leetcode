#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int budget = 0;
int totalCost = 0;
int arrSize = 0;

void BubbleSort(int *nums) {
    int swapCount = 1;
    while (swapCount) {
        swapCount = 0;
        for (int i = 0; i < arrSize-1; i++) {
            if (nums[i] > nums[i+1]) {
                swap(&nums[i], &nums[i+1]);
                swapCount++;
                totalCost++;
            }
            if (totalCost >= budget) {
                swapCount = 0;
                break;
            }
        }
    }
}

int main(void) {
    scanf("%d%d", &arrSize, &budget);
    int *nums = (int *) calloc(arrSize, sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Fail to malloc!!!");
        exit(1);
    }
    for (int i = 0; i < arrSize; i++) scanf("%d", &nums[i]);
    BubbleSort(nums);
    printArr(nums, arrSize, totalCost);
    free(nums);
    return 0;
}