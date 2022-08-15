class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& divs) {
       sort(begin(nums), end(nums));
    int div = reduce(begin(divs), end(divs), divs[0], [](int a, int b){ return gcd(a, b); });
    for (int i = 0; i < nums.size(); ++i)
        if (div % nums[i] == 0)
            return i;
    return -1;  
    }
};