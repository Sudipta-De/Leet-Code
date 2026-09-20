/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target,
              int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    /* Sort the array */
    for (int i = 1; i < numsSize; i++) {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }

    int capacity = 16;

    int **ans = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];

                if (sum == target) {

                    if (*returnSize == capacity) {
                        capacity *= 2;

                        ans = realloc(ans,
                                      capacity * sizeof(int *));

                        *returnColumnSizes = realloc(
                            *returnColumnSizes,
                            capacity * sizeof(int)
                        );
                    }

                    ans[*returnSize] = malloc(4 * sizeof(int));

                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[left];
                    ans[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return ans;
}