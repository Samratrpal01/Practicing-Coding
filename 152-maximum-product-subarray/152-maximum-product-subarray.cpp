class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int product=1;
        int Max=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            Max=max(Max,product*=nums[i]);
            if(nums[i]==0)
                product=1;
        }
        product=1;
        for(int i=n-1;i>-1;i--)
        {
            Max=max(Max,product*=nums[i]);
            if(nums[i]==0)
                product=1;
        }
        
        return Max;
    }
};