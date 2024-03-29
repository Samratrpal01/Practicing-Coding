class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*' and !st.empty())
                st.pop();
            else
            st.push(s[i]);
          
        }
        
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};