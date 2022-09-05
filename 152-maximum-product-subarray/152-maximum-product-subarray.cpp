class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int product=1;
        int Max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            Max=max(product*=nums[i],Max);
            if(nums[i]==0)
                product=1;
        }
        product=1;
        for(int i=n-1;i>=0;i--)
        {
            Max=max(product*=nums[i],Max);
            if(nums[i]==0)
                product=1;
        }
        
        return Max;
    }
};

