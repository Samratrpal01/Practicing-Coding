class Solution {
public:
    bool sub(string s,string t){

        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j])
                i++;
            j++;
        }
        return i==s.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int n=strs.size();

        int maxi=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(sub(strs[i],strs[j])&& i!=j){
                    count++;
                    break;
                }
            }
            if(count==0)
                maxi=max(maxi,int(strs[i].size()));
            
        }
        return maxi;
        
    }
};