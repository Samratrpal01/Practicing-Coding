class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto x:words)
            mp[x]++;
        
        bool flag=false;
        int count=0;
        for(auto x:words)
        {
            string w=x;
            reverse(x.begin(),x.end());
            if(w!=x and mp[x]>0 and mp[w]>0)
            {
                mp[x]--;
                mp[w]--;
                count+=4;
            }
            else if(x==w and mp[x]>1)
            {
                mp[x]-=2;
                count+=4;
            }
            else if(x==w and !flag and mp[x]>0)
            {
                mp[x]--;
                count+=2;
                flag=true;
            }
  
        }
        
        return count;
    }
};