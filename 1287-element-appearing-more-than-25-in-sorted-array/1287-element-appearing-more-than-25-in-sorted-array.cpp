class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int temp=n*0.25;
        map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        for(auto i:mp)
            if(i.second>temp)
                return i.first;
        
        return -1;
    }
};