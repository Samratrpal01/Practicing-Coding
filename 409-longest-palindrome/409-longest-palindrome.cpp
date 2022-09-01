class Solution {
public:
    int longestPalindrome(string s) {
      //  transform(s.begin(),s.end(),s.begin(),::tolower);
        vector<int>cnt(128,0);
        for(auto i:s)
            cnt[i]+=1;
       int res=0;
        for(int i=0;i<128;i++)
        {
            while(cnt[i]>1)
            {
                res+=2;
                cnt[i]-=2;
            }
        }
        for(int i=0;i<128;i++)
        {
            if(cnt[i])
            {
                res+=1;
                return res;
            }
        }
        return res;
    }
};