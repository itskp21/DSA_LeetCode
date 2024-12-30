class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        std::set<double> averages;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            double average = (nums[i] + nums[j]) / 2.0;
            averages.insert(average);
            i++;
            j--;
        }

        return averages.size();
    }
};