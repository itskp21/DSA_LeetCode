class Solution {
public:
    int reverseNumber(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;

        for (int num : nums) {
            int revNum = reverseNumber(num);
            int diff = num - revNum;

            if (freq.find(diff) != freq.end()) {
                count = (count + freq[diff]) % MOD;
            }
            
            freq[diff]++;
        }

        return count;
    }
};