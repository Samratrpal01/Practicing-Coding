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
    int hx,hy,px,py;
    void fun(TreeNode*root,int l,int x,int y,int prev)
    {   if(root==NULL)
            return;
        if(root->val==x)
        {
            hx=l;
            px=prev;
        }
     if(root->val==y)
     {
         hy=l;
         py=prev;
     }
        fun(root->left,l+1,x,y,root->val);
        fun(root->right,l+1,x,y,root->val);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        
        fun(root,0,x,y,0);
        if(hx==hy and px!=py)
            return true;
        else
        return false;
        
        
        
    }
};