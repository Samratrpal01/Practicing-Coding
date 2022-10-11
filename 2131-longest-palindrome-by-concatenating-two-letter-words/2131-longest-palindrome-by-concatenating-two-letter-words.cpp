class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto w:words)
        {
            mp[w]++;
        }
        int count=0;
            bool flag=false;
            for(auto x:words)
            {
                string w=x;
                reverse(w.begin(),w.end());
                if(w!=x and mp[x]>0 and mp[w]>0)
                {
                    mp[x]--;
                    mp[w]--;
                    count+=4;
                }
                else if(w==x and mp[x]>1)
                {
                    mp[x]-=2;
                    count+=4;
                }
                else if(w==x and !flag  and mp[x]>0)
                {
                    mp[x]-=1;
                    count+=2;
                    flag=true;
                }
            }
            
            return count;
        
    }
};
