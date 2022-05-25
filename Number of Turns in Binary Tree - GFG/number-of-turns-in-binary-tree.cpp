// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
   Node* lca(Node* root, int f,int s){
    if(root==nullptr)
        return root;
    if(root->data==f || root->data==s){
        return root;
    }
    Node *l = lca(root->left,f,s);
    Node *r = lca(root->right,f,s);
    
    if(l!=nullptr and r!=nullptr)
        return root;
    if(l!=nullptr)
        return l;
    return r;    
}
void path(Node* root, int d, string str, string &s){
    if(root==nullptr)
        return;
    if(root->data==d){
        s=str;
    }
    path(root->left,d,str+"l",s);
    path(root->right,d,str+"r",s);
}
int NumberOFTurns(struct Node* root, int first, int second)
{
  // Your code goes here
  if(root==nullptr || first==second)
    return 0;
  Node* lc = lca(root,first,second);
  string s1="",s2="";
  path(lc,first, "", s1);
  path(lc,second, "", s2);
  reverse(s1.begin(),s1.end());
  
  s1+=s2;
  int c=0;
  int f=0;
  for(int i=0;i<s1.length()-1;i++){
      if(s1[i]!=s1[i+1]){
          f=1;
          c++;
      }
  }
  if(f==0)
    return -1;
  return c;
}
};

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends