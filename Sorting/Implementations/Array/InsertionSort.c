#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

int budget = 0;
int totalCost = 0;
int arrSize = 0;

int insert(int index, int *nums) {
    int num = nums[index];
    int i = index - 1;
    for (; i >= 0; i--) {
        if (nums[i] <= num) break;
        nums[i+1] = nums[i];
        totalCost++;
        if (totalCost >= budget) {
            nums[i] = num;
            return -1;
        }
    }
    nums[i+1] = num;
    return 0;
}

void insertionSort(int *nums) {
    for (int i = 1; i < arrSize; i++) {
        if (insert(i, nums) == -1) return;
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
    insertionSort(nums);
    printArr(nums, arrSize, totalCost);
    free(nums);
    return 0;
}