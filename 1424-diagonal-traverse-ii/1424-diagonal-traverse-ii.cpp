class Solution {
public:
   struct comp {
    bool operator()(const vector<int>& x, const vector<int>& y) {
        return x[0]==y[0] ? x[1]<y[1] : x[0]>y[0];
    }
};

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    int n=nums.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<nums[i].size();j++) {
            pq.push(vector<int>{i+j, i, j});
        }
    }
    vector<int> elements;
    while (!pq.empty()) {
        vector<int> top=pq.top();
        pq.pop();
        elements.push_back(nums[top[1]][top[2]]);
    }
    return elements;
}
};