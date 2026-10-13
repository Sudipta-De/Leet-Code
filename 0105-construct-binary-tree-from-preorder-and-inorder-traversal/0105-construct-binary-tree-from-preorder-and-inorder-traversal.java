/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private Map<Integer, Integer> map;
    private int preIndex;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        map = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        preIndex = 0;
        return construct(preorder, 0, inorder.length - 1);
    }
    private TreeNode construct(int[] preorder, int left, int right) {
        if (left > right) {
            return null;
        }
        int rootVal = preorder[preIndex++];
        TreeNode root = new TreeNode(rootVal);
        int mid = map.get(rootVal);
        root.left = construct(preorder, left, mid - 1);
        root.right = construct(preorder, mid + 1, right);
        return root;
    }
}