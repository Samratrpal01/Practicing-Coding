// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    int findIndex(string str,int start,int end)
    {
        if(start>end)
            return -1;
            
            stack<char>st;
            for(int i=start;i<=end;i++)
            {
                if(str[i]=='(')
                    st.push('(');
                else if(str[i]==')')
                {
                    if(st.top()=='(')
                   { st.pop();
                    if(st.empty())
                    return i;
                }
                }
            }
            
        return -1;
    }
    Node *makeNode(string str,int start,int end)
    {
        if(start>end)
            return NULL;
        int num=0;
        while(start<=end and str[start]!='(' and str[start]!=')')
        {
            int x=str[start++]-'0';
            num=num*10+x;
        }
        --start;
        
        Node* root=new Node(num);
        int index=-1;
        
        if(start+1<end and str[start+1]=='(')
            index=findIndex(str,start+1,end);
        
        if(index!=-1)
        {
            root->left=makeNode(str,start+2,index-1);
            root->right=makeNode(str,index+2,end-1);
        }
        
        return root;
    }
    Node *treeFromString(string str)
    {
       int start=0,end=str.length()-1;
       return makeNode(str,start,end);
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends