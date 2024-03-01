/*
Problem Statement:
Given the root of a binary tree, return the leftmost value in the last row of the tree.

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* deepestLeft = root;
        int deepestDepth = 0;
        if(root->left)
            findLowestLeft(root->left, deepestLeft, 1, deepestDepth);
        if(root->right)
            findLowestLeft(root->right, deepestLeft, 1, deepestDepth);

        return deepestLeft->val;
    }

private:
    void findLowestLeft(TreeNode* node, TreeNode* &deepestLeft, int currdepth, int &deepestDepth) {
        if(!node->left && !node->right){
            if(currdepth > deepestDepth){
                deepestLeft = node;
                deepestDepth = currdepth;
            }

        }
        if(node->left)
            findLowestLeft(node->left, deepestLeft, currdepth + 1, deepestDepth);
        if(node->right)
            findLowestLeft(node->right, deepestLeft, currdepth + 1, deepestDepth);
    }   
};
