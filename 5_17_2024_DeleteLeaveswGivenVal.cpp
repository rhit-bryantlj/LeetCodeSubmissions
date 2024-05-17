/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left == NULL && root->right == NULL && root->val == target){
            return NULL;
        } else if(root->left == NULL && root->right == NULL){
            return root;
        } else{
            if(root->left != NULL)
                root->left = removeLeafNodes(root->left, target);
            if(root->right != NULL)
                root->right = removeLeafNodes(root->right, target);
            if(root->left == NULL && root->right == NULL && root->val == target){
                return NULL;
            }
            return root;
        }
        return root;
    }
};
