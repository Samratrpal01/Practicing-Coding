class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int cnt=0;
        int val=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++)
        {
            long long num=s[i]-'0';
            if((num*pow(2,cnt)+val)<=k)
            {val=val+num*pow(2,cnt);
                cnt++;
            }
        }
        
        return cnt++;
    }
};
