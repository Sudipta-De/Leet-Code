/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL)
        return NULL;
    int capacity = 10000;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    struct TreeNode** queue = malloc(capacity * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int levelSize = rear - front;
        result[*returnSize] = malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][i] = node->val;
            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;
        }
        (*returnSize)++;
    }
    free(queue);
    return result;
}