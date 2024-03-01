#include <stdio.h>
#include "MinHeap.h"

int main(void) {
    int numsSize;
    scanf("%d", &numsSize);
    int nums[numsSize];
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    MinHeap *heap = createHeap(nums, numsSize, numsSize * 2);
    showHeap(heap);
    insert(heap, 0);
    showHeap(heap);
    int min = deleteMax(heap);
    showHeap(heap);
    return 0;
}