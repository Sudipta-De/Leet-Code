/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        postIndex = n - 1;
        return construct(inorder, postorder, 0, n - 1);
    }

    TreeNode* construct(vector<int>& inorder, vector<int>& postorder,
                        int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        root->right = construct(inorder, postorder, mid + 1, right);
        root->left = construct(inorder, postorder, left, mid - 1);

        return root;
    }
};