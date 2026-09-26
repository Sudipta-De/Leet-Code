/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void dfs(int *candidates, int n, int target, int start,
         int *path, int depth, int **result, int *size, int *cols) {
    if (target == 0) {
        result[*size] = malloc(depth * sizeof(int));
        for (int i = 0; i < depth; i++)
            result[*size][i] = path[i];
        cols[*size] = depth;
        (*size)++;
        return;
    }

    for (int i = start; i < n; i++) {
        if (candidates[i] > target)
            break;

        path[depth] = candidates[i];

        dfs(candidates, n, target - candidates[i], i,
            path, depth + 1, result, size, cols);
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    int capacity = 10000;

    qsort(candidates, candidatesSize, sizeof(int), compare);

    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;

    int *path = malloc(target * sizeof(int));

    dfs(candidates, candidatesSize, target, 0,
        path, 0, result, returnSize, *returnColumnSizes);

    free(path);

    return result;
}