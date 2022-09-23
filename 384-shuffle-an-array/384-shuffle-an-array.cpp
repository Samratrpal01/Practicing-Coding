class Solution {
public:
    vector<int>v;
    vector<int>temp;
    Solution(vector<int>& nums) {
        v=nums;
        temp=nums;
    }
    
    vector<int> reset() {
        v=temp;
        return v;
    }
    
    vector<int> shuffle() {
        random_shuffle(v.begin(),v.end());
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */