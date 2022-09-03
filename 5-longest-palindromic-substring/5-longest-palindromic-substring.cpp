class Solution {
public:
    string longestPalindrome(string input1) {
        int n = input1.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        string count;
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; j++, i++)
            {
                if (g == 0)
                {
                    dp[i][j] = true;
                    if (count.size() < j+1 - i)
                        count = input1.substr(i, j-i+1);
                }
                else if (g == 1)
                {
                    if (input1[i] == input1[j])
                    {
                        dp[i][j] = true;
                        if(count.size() < j+1 - i)
                        count = input1.substr(i, j+1-i);
                    }
                }
                else
                {
                    if (input1[i] == input1[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                        if (count.size() < j+1 - i)
                            count = input1.substr(i, j+1-i);
                    }
                }
            }
        }
        return count;
    }
};