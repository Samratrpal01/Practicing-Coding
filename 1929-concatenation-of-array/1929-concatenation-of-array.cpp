class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>result=nums;
        for(int temp:nums)
        {
            result.push_back(temp);
        }
        
        
        return result;
    }
};