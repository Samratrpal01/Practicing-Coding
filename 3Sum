Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

Codes Are:-
vector<vector<int>> threeSum(vector<int>& nums) {
       sort(begin(nums), end(nums));
        set<vector<int>> st;
        for(int i=0;i<nums.size();i++)
        {
            int lo=i+1;
            int hi=nums.size()-1;
            while(lo<hi)
            {
                int sum=nums[i]+nums[lo]+nums[hi];
                if(sum==0){
                    st.insert(vector<int> {nums[i], nums[lo], nums[hi]});
                    lo++;
                    while(lo<hi&&nums[lo]==nums[lo-1])lo++;
                }
                else if(sum<0)lo++;
                else hi--;
            }
        }
        vector<vector<int>> ans(begin(st), end(st));
        return ans;
    }
