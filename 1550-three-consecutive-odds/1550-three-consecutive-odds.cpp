class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<=2)
            return false;
        int n=arr.size();
        for(int i=0;i<=n-3;i++)
        {
            if(arr[i]&1 and arr[i+1]&1 and arr[i+2]&1)
                return true;
        }
        return false;
    }
};