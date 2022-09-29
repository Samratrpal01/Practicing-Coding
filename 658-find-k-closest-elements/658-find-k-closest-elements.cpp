int t;
    bool cmp(int a,int b)
    {
        if(abs(a-t)==abs(b-t))
            return a<b;
        else
            return abs(a-t)<abs(b-t);
    }
class Solution {
    
public:
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        t=x;
    
        sort(arr.begin(),arr.end(),cmp);
       
        for(int i=0;i<k;i++)
        {
           result.push_back(arr[i]);
        }
        sort(result.begin(),result.end());
        return result;
    }
};