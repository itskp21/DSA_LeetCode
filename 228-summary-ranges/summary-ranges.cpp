class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> result;
        if (nums.empty()) return result;

        int start = nums[0];
        int end = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                // Extend the range
                end = nums[i];
            } else {
                // Finalize the current range
                if (start == end) {
                    result.push_back(std::to_string(start));
                } else {
                    result.push_back(std::to_string(start) + "->" + std::to_string(end));
                }
                // Start a new range
                start = nums[i];
                end = nums[i];
            }
        }

        // Add the last range
        if (start == end) {
            result.push_back(std::to_string(start));
        } else {
            result.push_back(std::to_string(start) + "->" + std::to_string(end));
        }

        return result;
    }
};