class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>v(10,0);
        for(auto i:num)
        {
            v[i-'0']+=1;
        }
        
        string lp="",rp="";
        for(auto i:num)
        {
            for(int j=9;j>-1;j--)
            {
                if(v[j]>1 and (j>0 or !lp.empty()))
                {
                    lp+='0'+j;
                    rp+='0'+j;
                    v[j]-=2;
                    break;
                }
            }
        }
        
        reverse(rp.begin(),rp.end());
        for(int i=9;i>-1;i--)
        {
            if(v[i])
            {       lp+='0'+i;
            break;
        }
        }
        
        return lp+rp;
    }
};