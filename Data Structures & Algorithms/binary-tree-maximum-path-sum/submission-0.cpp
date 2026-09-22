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
    int max_sum;
    private:
    int dfs(TreeNode*node){
        if(node==nullptr){
            return 0;
        }
        int leftmax=max(0,dfs(node->left));
        int rightmax=max(0,dfs(node->right));
        int currentpathsum = node->val+leftmax+rightmax;
        max_sum = max(max_sum,currentpathsum);
        return node->val+max(leftmax,rightmax);
    }
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;

    }
};
