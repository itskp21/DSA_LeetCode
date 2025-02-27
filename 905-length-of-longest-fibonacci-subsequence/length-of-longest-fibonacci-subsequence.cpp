class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        unordered_map<int, int> dp;
        int maxLen = 0;
        
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < k; j++) {
                int x = arr[k] - arr[j];
                if (x < arr[j] && index.count(x)) {
                    int i = index[x];
                    int len = dp[i * n + j] + 1;
                    dp[j * n + k] = len;
                    maxLen = max(maxLen, len + 2);
                }
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
};