class Solution {
public:
    bool canPlaceFlowers(vector<int> v, int n) {
    v.insert(v.begin(),0);
        v.push_back(0);
        for(int i=1;i<v.size()-1;i++)
        {
            if(v[i-1]+v[i]+v[i+1]==0)
            {
                n--;
                i++;
            }
        }
        
        return n<=0;
    }
};