/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void backtrack(int start,int n,int k,int* current,int depth,int** result,int* returnSize,int* returnColumnSizes){
    if(depth ==k){
        result[*returnSize] =(int*)malloc(k * sizeof(int));
        for(int i =0;i<k;i++){
            result[*returnSize][i] = current[i];
        }
        returnColumnSizes[*returnSize]=k;
        (*returnSize)++;
        return;
    }
    for(int i = start;i<=n;i++){
        current[depth]=i;
        backtrack(i+1,n,k,current,depth+1,result,returnSize,returnColumnSizes);
    }
        
 }
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int maxSize=1<<n;
    int** result=(int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
    *returnSize=0;
    int* current = (int*)malloc(k * sizeof(int));
    backtrack(1,n,k,current,0,result,returnSize,*returnColumnSizes);
    free(current);
    return result;
}