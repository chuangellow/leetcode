#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {
    int *arr;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void showHeap(MinHeap* minHeap) {
    printf("size: %d\n", minHeap->size);
    for (int i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->arr[i]);
    }
    printf("\n");
}

void heapify(MinHeap* minHeap, int index) {
    int left = index * 2 + 1;
    int right = left + 1;
    int min = index;
    if (left >= minHeap->size || left <= 0) left = -1;
    if (right >= minHeap->size || right <= 0) right = -1;
    if (left != -1 && minHeap->arr[left] < minHeap->arr[min]) { min = left; }
    if (right != -1 && minHeap->arr[right] < minHeap->arr[min]) { min = right; }
    if (min != index) {
        swap(&minHeap->arr[index], &minHeap->arr[min]);
        heapify(minHeap, min);
    }
}

MinHeap *createHeap(int *nums, int arrSize, int capacity) {
    MinHeap* minHeap = (MinHeap *) malloc(sizeof(MinHeap));
    if (minHeap == NULL) {
        printf("Fail to malloc!!!\n");
        return NULL;
    }
    int *arr = (int *) calloc(sizeof(int), capacity);
    if (arr == NULL) {
        printf("Fail to malloc!!!\n");
        return NULL;
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = nums[i];
    }
    minHeap->size = arrSize;
    minHeap->capacity = capacity;
    minHeap->arr = arr;
    int index = (arrSize - 2) / 2;
    for (int index = (arrSize - 2) / 2; index >= 0; index--) {
        heapify(minHeap, index);
    }
    return minHeap;
}

void insert(MinHeap *minHeap, int num) {
    if (minHeap->size + 1 >= minHeap->capacity) {
        printf("The heap is full!!!\n");
        return;
    }
    minHeap->arr[minHeap->size] = num;
    minHeap->size = minHeap->size + 1;
    int currentIndex = minHeap->size - 1;
    int parentIndex = (currentIndex - 1) / 2;
    while (parentIndex >= 0) {
        if (minHeap->arr[currentIndex] >= minHeap->arr[parentIndex]) {
            break;
        }
        swap(&minHeap->arr[currentIndex], &minHeap->arr[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = (parentIndex - 1) / 2;
    }
}

int deleteMax(MinHeap *minHeap) {
    if (minHeap->size <= 0) {
        printf("The heap is empty!!!\n");
        return -1;
    }
    int ret = minHeap->arr[0];
    int lastIndex = minHeap->size - 1;
    minHeap->arr[0] = minHeap->arr[lastIndex];
    minHeap->size--;
    int index = 0;
    int left = 1;
    int right = 2;
    int min = index;
    if (left >= minHeap->size || left <= 0) left = -1;
    if (right >= minHeap->size || right <= 0) right = -1;
    while (left != -1 && right != -1) {
        if (left != -1 && minHeap->arr[left] < minHeap->arr[min]) min = left;
        if (right != -1 && minHeap->arr[right] < minHeap->arr[min]) min = right;
        swap(&minHeap->arr[min], &minHeap->arr[index]);
        index = min;
        left = index * 2 + 1;
        right = index * 2 + 2;
        if (left >= minHeap->size || left <= 0) left = -1;
        if (right >= minHeap->size || right <= 0) right = -1;
    }
    return ret;
}