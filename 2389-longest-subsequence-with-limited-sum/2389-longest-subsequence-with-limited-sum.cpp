class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
     int n=nums.size();
     int m=queries.size();
        vector<int>res;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        for(int i=0;i<m;i++)
        {   int count=0;
            for(int j=0;j<n;j++)
            {
                if(queries[i]>=nums[j])
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};