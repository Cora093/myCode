#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = NULL;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        int j = 0;
        for (j = i + 1; j < numsSize; j++) {
            if (target - *(nums + i) == *(nums + j)) {
                *returnSize = 2;
                ret = (int*)malloc(2 * sizeof(int*));
                *ret = i;
                *(ret + 1) = j;
                return ret;
                free(ret);
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


