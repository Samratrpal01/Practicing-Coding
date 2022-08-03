class Solution {
public:
    vector<int>subset;
    static bool comp(vector<int>temp1,vector<int>temp2)
    {
        if(temp1.size()==temp2.size())
            return temp1[0]<temp2[0];
        else
            return temp1.size()<temp2.size();
    }
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
        sort(result.begin(),result.end(),comp);
        return result;
    }
};