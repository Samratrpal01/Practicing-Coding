class Solution {
public:
    string reverseWords(string s) {
        string result="";
        stringstream ss(s);
        string sss="";
        while(ss>>sss)
        {
            reverse(sss.begin(),sss.end());
            if(result=="")
            result+=sss;
            else
            {
                result+=" ";
                result+=sss;
            }
            
        }
        return result;
    }
};