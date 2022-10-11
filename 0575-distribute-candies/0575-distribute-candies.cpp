class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        n/=2;
        set<int>s;
        for(int temp:candyType)
        {
            s.insert(temp);
        }
        
        if(s.size()>=n)
            return n;
        else
            return s.size();
            
            
    }
};