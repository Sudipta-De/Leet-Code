/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int size = 1<<n;
    int* result = (int*)malloc(size * sizeof(int));
    *returnSize= size;
    for(int i =0;i<size;i++){
        result[i]=i^(i>>1);
    }
    return result;
}