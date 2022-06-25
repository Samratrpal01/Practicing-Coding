class Solution {
public:
    bool checkZeroOnes(string s) {
        int count1=0,count0=0;
        int max1=0,max0=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                count1++;
                if(s[i]!=s[i+1])
                {
                    max1=max(count1,max1);
                    count1=0;
                }
            }
            else
            {
                count0++;
                if(s[i]!=s[i+1])
                {
                    max0=max(max0,count0);
                    count0=0;
                }
            }
        }
        
        if(max1>max0)
            return true;
        else
            return false;
    }
};