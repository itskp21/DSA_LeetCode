class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0; // Total sum of the array
        for (int num : nums) {
            total_sum += num;
        }

        long long prefix_sum = 0; // Prefix sum tracker
        int count = 0;            // Count of valid splits

        // Iterate through the array for valid split points
        for (int i = 0; i < n - 1; ++i) {
            prefix_sum += nums[i];
            long long suffix_sum = total_sum - prefix_sum;

            // Check the valid split condition
            if (prefix_sum >= suffix_sum) {
                ++count;
            }
        }

        return count;
    }
};