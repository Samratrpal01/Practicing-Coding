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
   void helper(TreeNode* root, map<int, map<int, vector<int>>>& order, int row, int col) {
        if (root == nullptr) return;
        auto& row_map = order[col];
        row_map[row].push_back(root->val);
        helper(root->left, order, row+1, col-1);
        helper(root->right, order, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> order;
        helper(root, order, /*row=*/0, /*col=*/0);
        
        vector<vector<int>> result;
        for (auto& [col, col_map] : order) {
            vector<int> row_vec;
            for (auto& [row, row_vals] : col_map) {
                sort(row_vals.begin(), row_vals.end()); 
                row_vec.insert(row_vec.end(), row_vals.begin(), row_vals.end());
            }
            result.push_back(row_vec);
        }
        return result;
    }
};