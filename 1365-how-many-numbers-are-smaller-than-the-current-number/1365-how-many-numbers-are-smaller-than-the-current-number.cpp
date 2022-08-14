class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>nums1(nums.begin(),nums.end());
        sort(nums1.begin(),nums1.end());
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            if(find(nums1.begin(),nums1.end(),nums[i])!=nums1.end())
                result.push_back(find(nums1.begin(),nums1.end(),nums[i])-nums1.begin());
        }
        
        return result;
    }
};