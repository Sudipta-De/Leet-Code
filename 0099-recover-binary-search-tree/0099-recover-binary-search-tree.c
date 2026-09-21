/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root) {
    struct TreeNode *current = root;
    struct TreeNode *prev = NULL;
    struct TreeNode *first = NULL;
    struct TreeNode * second = NULL;
    while (current !=NULL){
        if(current -> left ==NULL){
            if(prev != NULL && prev->val > current -> val){
                if(first == NULL)
                    first = prev;
                second=current;
            }
            prev = current;
            current = current -> right;
        }
        else{
            struct TreeNode *predecessor = current->left;
            while (predecessor->right != NULL && predecessor-> right !=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){
                predecessor->right=current;
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                if(prev!=NULL && prev->val >current->val){
                    if(first == NULL)
                        first=prev;
                    second=current;
                }
                prev = current;
                current= current ->right;
            }
        }
    }
    int temp= first->val;
    first->val = second->val;
    second->val=temp;
}