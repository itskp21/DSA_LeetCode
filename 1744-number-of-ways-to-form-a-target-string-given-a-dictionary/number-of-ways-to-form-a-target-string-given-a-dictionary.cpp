class Solution {
public:
     
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = words.size();
        int n = words[0].size();
        int tLen = target.size();

        // Count frequency of each character at each position in words
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < n; ++i) {
                freq[i][word[i] - 'a']++;
            }
        }

        vector<vector<long long>> dp(tLen + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1; // Base case: one way to form empty target

        for (int i = 0; i <= tLen; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < tLen) {
                    char targetChar = target[i];
                    int charIdx = targetChar - 'a';

                    dp[i + 1][j + 1] += dp[i][j] * freq[j][charIdx] % MOD;
                    dp[i + 1][j + 1] %= MOD;
                }
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
        return dp[tLen][n];
    }
};