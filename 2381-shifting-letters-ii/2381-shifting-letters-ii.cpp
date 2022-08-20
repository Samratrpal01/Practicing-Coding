class Solution {
public:
constexpr int static n = 50000;
int bt[n + 1] = {};
int prefix_sum(int i)
{
    int sum = 0;
    for (i = i + 1; i > 0; i -= i & (-i))
        sum += bt[i];
    return sum;
}
void add(int i, int val)
{
    for (i = i + 1; i <= n; i += i & (-i))
        bt[i] += val;
}
string shiftingLetters(string s, vector<vector<int>>& shifts) {
    for (auto &shift : shifts) {
        add(shift[0], shift[2] == 1 ? 1 : -1);
        add(shift[1] + 1, shift[2] == 1 ? -1 : 1);
    }
    for (int i = 0; i < s.size(); ++i) {
        int ch = s[i] - 'a';
        ch = (26 + ch + (prefix_sum(i) % 26)) % 26;
        s[i] = 'a' + ch;
    }
    return s;
}
};