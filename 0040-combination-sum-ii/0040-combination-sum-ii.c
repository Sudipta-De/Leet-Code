/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void dfs(int *candidates, int n, int target, int start,
         int *path, int depth,
         int **result, int *returnSize, int *returnColumnSizes) {

    if (target == 0) {
        result[*returnSize] = malloc(depth * sizeof(int));

        for (int i = 0; i < depth; i++) {
            result[*returnSize][i] = path[i];
        }

        returnColumnSizes[*returnSize] = depth;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < n; i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        path[depth] = candidates[i];
        dfs(candidates, n, target - candidates[i], i + 1,
            path, depth + 1,
            result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int capacity = 1000;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    int *path = malloc(candidatesSize * sizeof(int));
    dfs(candidates, candidatesSize, target, 0,
        path, 0,
        result, returnSize, *returnColumnSizes);
    free(path);
    return result;
}