class Solution {
public:
    static bool comp(int a,int b)
    {  int temp1=__builtin_popcount(a);
     int temp2=__builtin_popcount(b);
     if(temp1==temp2)
         return a<b;
     return temp1<temp2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
        
    }
};