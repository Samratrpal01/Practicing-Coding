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
#include<bits/stdc++.h>
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return 0;
        vector<int>v;
        inorder(root,v);
        int minv=INT_MAX;
       
        
        
       int n=v.size();
        for(int i=0;i<n-1;i++)
        {
            if(minv>(v[i+1]-v[i]))
                minv=v[i+1]-v[i];
        }
        
        return minv;
    }
};