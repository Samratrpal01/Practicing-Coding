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
      int cnt = 0;
    void countPaths(TreeNode* root, long long int sum){
        if(!root) {
            return;
        }
        sum -= root->val;
        if(sum == 0) {
            ++cnt;
        }
        countPaths(root->left, sum);
        countPaths(root->right, sum);
    }
    
    void path_sum(TreeNode* root, long long int Target)
    {
        if(!root) return;
        countPaths(root, Target);
        path_sum(root->left, Target);
        path_sum(root->right, Target);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        path_sum(root, (long long int)targetSum);
        return cnt;
    }
   
};