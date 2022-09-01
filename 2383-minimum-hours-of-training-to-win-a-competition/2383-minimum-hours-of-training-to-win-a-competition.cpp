class Solution {
public:
    int minNumberOfHours(int in, int initial, vector<int>& energy, vector<int>& experience) {
        int curr_exp=initial,need=0;
        for(int i=0;i<experience.size();curr_exp+=experience[i++])
        {
            need+=max(0,experience[i]-need-curr_exp+1);
        }
        
        
        return max(accumulate(begin(energy),end(energy),1)-in,0)+need;
    }
};