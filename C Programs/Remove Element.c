#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int newSize = removeElement(nums, 4, val);
    printf("New size: %d\n", newSize);
    printf("Result: [");
    for (int i = 0; i < newSize; i++) {
        printf("%d", nums[i]);
        if (i < newSize - 1) printf(",");
    }
    printf("]\n");
    return 0;
}
