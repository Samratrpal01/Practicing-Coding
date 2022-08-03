class Solution {
public:
     vector<int>permutations;
    int n;
    bool chosen[10];
   
    void search(vector<vector<int>>&result,vector<int>nums)
    {
        if(permutations.size()==n)
            result.push_back(permutations);
        else
        {   for(int i=0;i<n;i++)
        {   if(chosen[i])
                continue;
            chosen[i]=true;
            permutations.push_back(nums[i]);
            search(result,nums);
            chosen[i]=false;
            permutations.pop_back();
        }
        }
    }
   
    vector<vector<int>> permute(vector<int>& nums) {
      n=nums.size();
         vector<vector<int>>result;
        search(result,nums);
        return result;
        
    }
};