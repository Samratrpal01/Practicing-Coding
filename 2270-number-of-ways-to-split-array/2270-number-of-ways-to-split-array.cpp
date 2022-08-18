class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>result(n,0);
        result[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            result[i]=(long long)(result[i-1]+nums[i]);
        }
       
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(result[i]>=result[n-1]-result[i])
                count++;
        }
        return count;
    }
};