class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    set<int>s;
        for(auto i:nums)
        {
            if(s.find(i)!=s.end())
                continue;
            s.insert(i);
            auto it=s.upper_bound(i);
            if(it!=s.end())
                s.erase(it);
        }
        
        return s.size();
    }
};