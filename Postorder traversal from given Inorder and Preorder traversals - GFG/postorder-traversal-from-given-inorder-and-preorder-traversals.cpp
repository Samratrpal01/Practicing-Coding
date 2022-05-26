// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


/*prints the post order traversal of the 
tree */
unordered_map<int,int>m;
void post(int in[],int pre[],int l,int h,int &index)
{
    if(l>h)
    return;
    int p=m[pre[index++]];
    post(in,pre,l,p-1,index);
    post(in,pre,p+1,h,index);
    cout<<in[p]<<" ";
}
void printPostOrder(int in[], int pre[], int n)
{
    int index=0;
    for(int i=0;i<n;i++)
    m[in[i]]=i;
        post(in,pre,0,n-1,index);
        m.clear();
    
}