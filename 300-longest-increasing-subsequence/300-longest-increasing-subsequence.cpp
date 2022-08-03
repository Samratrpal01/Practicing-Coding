class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result=INT_MIN;
       vector<int>v(nums.size());
       
           for(int i=0;i<nums.size();i++)
           {v[i]=1;
               for(int k=0;k<i;k++)
               {
                   if(nums[k]<nums[i])
                       v[i]=max(v[i],v[k]+1);
                   
               }
           }
        
        return *max_element(v.begin(),v.end());
       
        
    }
};