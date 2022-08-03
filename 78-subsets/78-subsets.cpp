class Solution {
public:
    vector<int>subset;
    void search(vector<vector<int>>&result,vector<int>nums,int index)
    {
        if(index==nums.size())
            result.push_back(subset);
        else
        {
            subset.push_back(nums[index]);
            search(result,nums,index+1);
            subset.pop_back();
            search(result,nums,index+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        search(result,nums,0);
        sort(result.begin(),result.end());
        return result;
    }
};