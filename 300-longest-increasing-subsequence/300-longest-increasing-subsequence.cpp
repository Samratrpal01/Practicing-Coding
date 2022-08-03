class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(auto i:nums)
        {
            auto it=lower_bound(res.begin(),res.end(),i);
            if(it==res.end())
                res.push_back(i);
            else
                *it=i;
        }
        
        return res.size();
    }
};