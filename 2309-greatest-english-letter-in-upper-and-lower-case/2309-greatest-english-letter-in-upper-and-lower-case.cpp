class Solution {
public:
    string greatestLetter(string s) {
        string temp="";
        sort(s.begin(),s.end());
        for(auto i=0;i<s.length();i++)
        {
            if(s[i]>='A' and s[i]<='Z')
            {
                if(find(s.begin(),s.end(),(s[i]-'A')+97)!=s.end())
                   {
                       temp=s[i];
                   }
            }
        }
        
        return temp;
    }
};