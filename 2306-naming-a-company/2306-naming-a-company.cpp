class Solution {
public:
    long long distinctNames(vector<string>& v) {
      int n=v.size();
        unordered_set<string> u(v.begin(),v.end()); 
        int mp[26][26]={0}; // mp[i][j] Store how many first letter i are good with having first letter j
        vector<vector<int>> d(n,vector<int>(26,0));   //Store whether string at i th index can have first letter as one of the ['a'...'z'] 26 alphabets
        for(int i=0;i<n;++i)
        {
            string r=v[i];
            for(int j=0;j<26;++j)
            {
                r[0]='a'+j;
                if(u.find(r)==u.end())
                {
                    d[i][j]=1;
                    mp[v[i][0]-'a'][j]++;      //storing all the strings with first letter same as ith string which are good with having first letter
											 //as jth alphabet
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<26;++j)
            {
                if(d[i][j])
                    ans+=mp[j][v[i][0]-'a'];  //since d[i][j]=1 therefore the ith index string can take j as first letter therefore we add
											  //all the string starting with 'a'+j who are also good with having current ith strings first letter 
            }
        }
        return ans;  
    }
};