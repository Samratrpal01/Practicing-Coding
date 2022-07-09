class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
           sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int i=0,j=0,ans=1;
        while (i<buses.size()&&j<passengers.size()) {
            int cnt=0;
            while (j<passengers.size()&&cnt<capacity) {
                if (passengers[j]<=buses[i]) {
                    if (j>0&&passengers[j-1]==passengers[j]-1) ans=ans;
                    else ans=passengers[j]-1;
                    j++;
                    cnt++;
                }
                else break;
            }
            i++;
            if (i==buses.size()&&cnt!=capacity) {
                if (j>0&&passengers[j-1]!=buses[i-1]||j==0) return buses[i-1];
            }
        }
        if (j==passengers.size()) {
            if (i!=buses.size()) return buses[buses.size()-1];
        }
        return ans;
    }
    
};