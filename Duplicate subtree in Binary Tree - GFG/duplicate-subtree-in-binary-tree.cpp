// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<int,vector<Node*>>mp;
    bool chk(Node*r1,Node*r2)
    {
        if(r1==NULL)
        {
            if(r2!=NULL)
            return false;
            
        }
        if(r2==NULL)
        {
            if(r1!=NULL)
            return false;
            return true;
        }
        if(r1->data!=r2->data)
        return false;
        bool ok=true;
        ok=ok&&chk(r1->left,r2->left);
        ok=ok&&chk(r1->right,r2->right);
        return ok;
    }
    void solve(Node*root,int& ans)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL and root->right==NULL)
        return;
        if(mp[root->data].size()>0)
        {
            for(int i=0;i<mp[root->data].size();i++)
            {
                if(chk(root,mp[root->data][i]))
                {
                    ans=1;
                    break;
                }
            }
            
            
        }
        mp[root->data].push_back(root);
        solve(root->left,ans);
        solve(root->right,ans);
        
    }
    int dupSub(Node *root) {
        if(root==NULL)
        return 0;
        int ans=0;
        solve(root,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends