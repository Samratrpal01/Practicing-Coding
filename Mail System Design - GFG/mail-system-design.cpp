// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *left; 
    Node *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

 // } Driver Code Ends
//User function Template for C++
/*Given below is the structure of Node:
the list moves from left to right
struct Node{
    int data;
    Node *left; 
    Node *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution{
public:
   vector<Node*> mailDesign(int N, int Q, int query[]){
       // code here
       vector<int> u,r,t;
       for(int i=0; i<N; i++)
       u.push_back(i+1);
       
       for(int i=1; i<Q*2; i+=2)
       {
           if(query[i-1]==1)
           {
               u.erase(find(u.begin(), u.end(), query[i]));
               r.push_back(query[i]);
           }
           else if(query[i-1]==2)
           {
               r.erase(find(r.begin(), r.end(), query[i]));
               t.push_back(query[i]);
           }
           else if(query[i-1]==3)
           {
               u.erase(find(u.begin(), u.end(), query[i]));
               t.push_back(query[i]);
           }
           else 
           {
               t.erase(find(t.begin(), t.end(), query[i]));
               r.push_back(query[i]);
           }
       }
       Node* unread=NULL,*u1, *read=NULL,*r1, *trash=NULL, *t1;
       if(u.size())
               unread= new Node(u[0]);
               
       if(r.size())
         read= new Node(r[0]);
         
       if(t.size())
       trash= new Node(t[0]);
       
       u1=unread;
       r1=read;
       t1=trash;
       
       for(int i=1; i<u.size(); i++)
       {
           Node* p= new Node(u[i]);
           unread->right=p;
           p->left=unread;
           unread=p;
       }
        for(int i=1; i<r.size(); i++)
       {
           Node* p= new Node(r[i]);
           read->right=p;
           p->left=read;
           read=p;
       }
        for(int i=1; i<t.size(); i++)
       {
           Node* p= new Node(t[i]);
           trash->right=p;
           p->left=trash;
           trash=p;
       }
       
       vector<Node*> v;
       v.push_back(u1);
       v.push_back(r1);
       v.push_back(t1);
       return v;
       
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int query[2*Q];
        for(int i = 0;i < 2*Q;i++)
            cin>>query[i];
        
        Solution ob;
        vector<Node*> ans = ob.mailDesign(N, Q, query);
        for(int i = 0;i < 3;i++){
            if(ans[i] == NULL)
                cout<<"EMPTY\n";
            else{
                Node *p = ans[i];
                while(p != NULL){
                    cout<<p->data<<" ";
                    p = p->right;
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}  // } Driver Code Ends