class Solution {
public:
    pair<int,int> getBestIndex(vector<int>& nums, int start, int span) {
	// get index and maximum
        int max_idx = 0;
        int max_ = nums[start];
        int i = 1;
        while (i < span) {
            auto val = nums[start+i];
            if (val > max_) {
                max_idx = i;
                max_ = val;
                if (max_ == 9) break;
            }
            i++;
        }
        return pair<int,int>(max_idx, max_);
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best_seq;
        set<pair<int,int>> list_indices = {{0,0}};
        while (k-- > 0) {
            set<pair<int,int>> next_list_indices;
            int max_ = -1;
            for (auto indices : list_indices) {
                auto n1 = indices.first;
                auto n2 = indices.second;
                auto remaining = nums1.size() + nums2.size() - n1 - n2 - k;
                int idx1, max1 = -1, idx2, max2 = -1;
                auto remaining1 = min(remaining, nums1.size() - n1);
                auto remaining2 = min(remaining, nums2.size() - n2);
                if (remaining1)
                    tie(idx1, max1) = getBestIndex(nums1, n1, remaining1);
                if (remaining2)
                    tie(idx2, max2) = getBestIndex(nums2, n2, remaining2);
                auto max12 = max(max1, max2);
                if (max12 < max_) continue;
                if (max12 > max_) { max_ = max12; next_list_indices.clear(); }
                if (max1 >= max2) next_list_indices.insert({n1+idx1+1, n2});
                if (max1 <= max2) next_list_indices.insert({n1, n2+idx2+1});
            }
            best_seq.emplace_back(max_);
            list_indices = move(next_list_indices);
        }
        return best_seq;
    }
};