/**
* Problem statement
* Given the roots of two binary trees p and q, write a function to check if they are the same or not.
*
* Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = false;
        // Make recursive helper and call with the root nodes
        isSame = sameTreeFinder(p, q);
        return isSame;
        
    }

private:
    bool sameTreeFinder(TreeNode* p, TreeNode* q) {
        // Check for single null nodes that do not equal and return false
        if((!p && q) || (!q && p)) return false;
        // If both nodes are false, they match and return true
        if((!p && !q)) return true;
        // If values are not equal return false (null must be checked before value)
        if(p->val != q->val) return false;

        bool leftTruth = sameTreeFinder(p->left, q->left);
        bool rightTruth = sameTreeFinder(p->right, q->right);
        
        if(leftTruth && rightTruth) return true;
        else return false;
    }
};
