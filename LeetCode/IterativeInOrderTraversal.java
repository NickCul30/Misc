// IterativeInOrderTraversal.java
// Nicholas Culmone
// September 8th 2022
// Expansion on the problem 94. Binary Tree Inorder Traversal, by doing the problem iteratively,
// as opposed to the trivial recursive solution.

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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> li = new ArrayList<Integer>();
        Stack<TreeNode> stk = new Stack<TreeNode>();
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode cur = stk.peek();
            if(cur == null) break;
            
            if(cur.left != null && cur.left.val != -101){
                stk.push(cur.left);            
            }
            else{
                li.add(cur.val);
                cur.val = -101;
                stk.pop();
                
                if(cur.right != null && cur.right.val != -101) stk.push(cur.right);
            }
        }
        
        return li;
    }
}