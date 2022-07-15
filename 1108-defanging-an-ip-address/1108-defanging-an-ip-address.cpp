class Solution {
public:
    string defangIPaddr(string address) {
        string result="";
        int n=address.size();
        for(int i=0;i<n;i++)
        {
            if(address[i]!='.')
                result+=to_string(address[i]-'0');
            else
                result+="[.]";
                
        }
        return result;
    }
};