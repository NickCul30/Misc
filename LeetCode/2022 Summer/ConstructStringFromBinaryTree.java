// ConstructStringFromBinaryTree.java
// Nicholas Culmone
// September 7th, 2022
// DCC September 2022 Problem

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
    public String tree2str(TreeNode root) {
        String ans = "" + root.val;
        if(root.left != null) ans += "(" + tree2str(root.left) + ")";
        if(root.left == null && root.right != null) ans += "()(" + tree2str(root.right) + ")";
        else if(root.right != null) ans += "(" + tree2str(root.right) + ")";
        
        return ans;
    }
}