class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        int i,a[n+2],mx=0;
        a[0]=0,a[1]=1;
        for(i=2;i<n+1;i++)
        {
            if(i%2==0) a[i]=a[i/2];
            else a[i]=a[i/2]+a[(i/2)+1];
        }
        return *max_element(a,a+n+1);
    }
};