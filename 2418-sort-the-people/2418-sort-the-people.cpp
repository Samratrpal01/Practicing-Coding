bool cmp(pair<string,int> a , pair<string,int> b){
if(a.second!=b.second){
return a.second > b.second;
}
return a.first>b.first;
}
class Solution {
public:

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n=names.size();
    vector<pair<string,int>> vp(n);    
    for(int i=0;i<n;i++){
        vp[i]=make_pair(names[i],heights[i]);
    }
    sort(vp.begin(),vp.end(),cmp);
    vector<string> s;
    for(auto x:vp){
        s.push_back(x.first);
    }
    return s;
}
    
};