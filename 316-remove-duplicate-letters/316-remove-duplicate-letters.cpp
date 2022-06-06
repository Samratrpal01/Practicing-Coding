class Solution {
public:
    string removeDuplicateLetters(string p) {
       vector<bool>vis(256,0);
        vector<int>mp(128,0);
        string res="";
        for(int i=0;i<p.length();i++)
        {
            mp[p[i]]++;
        }
        for(int i=0;i<p.length();i++)
        {
            mp[p[i]]--;
            
            if(vis[p[i]]==true)
                continue;
            while(!res.empty() and res.back()>p[i] and mp[res.back()]>0)
            {
                vis[res.back()]=false;
                res.pop_back();
            }
            
            res+=p[i];
            vis[p[i]]=true;
        }
        return res;
    }
   
      
};

