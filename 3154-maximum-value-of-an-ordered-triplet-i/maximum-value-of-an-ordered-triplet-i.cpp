class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        typedef long long ll;
        int n = nums.size();

        if (n < 3) return 0;
        
        int maxPrefix = INT_MIN;
        ll result = 0;
        vector<int> maxSuffix(n, 0);
        
        maxSuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(maxSuffix[i + 1], nums[i]);
        }
        
        for (int j = 1; j < n - 1; ++j) {
            maxPrefix = max(maxPrefix, nums[j - 1]);
            ll tripletValue = (ll)(maxPrefix - nums[j]) * maxSuffix[j + 1];
            result = max(result, tripletValue);
        }
        
        return max(0LL, result);
    }
};