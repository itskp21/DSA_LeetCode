class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = std::accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        
        vector<bool> dp(totalSum / 2 + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int i = totalSum / 2; i >= stone; --i) {
                dp[i] = dp[i] || dp[i - stone];
            }
        }

        for (int i = totalSum / 2; i >= 0; --i) {
            if (dp[i]) {
                return totalSum - 2 * i;  
            }
        }
        return 0;
    }
};