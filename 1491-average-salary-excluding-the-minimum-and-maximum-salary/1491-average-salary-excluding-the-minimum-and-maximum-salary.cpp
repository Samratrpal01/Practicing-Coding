class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        long long result=0;
        for(int i=1;i<salary.size()-1;i++)
            result+=salary[i];
        return ((double)result/((double)salary.size()-2));
    }
};