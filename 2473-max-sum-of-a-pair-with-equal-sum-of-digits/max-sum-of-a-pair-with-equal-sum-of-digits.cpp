class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; 
        int maxSum = -1;

        for (int num : nums) {
            int sum = digitSum(num);
            
            if (digitSumMap.find(sum) != digitSumMap.end()) {
                maxSum = max(maxSum, num + digitSumMap[sum]);
                digitSumMap[sum] = max(digitSumMap[sum], num);
            } else {
                digitSumMap[sum] = num;
            }
        }
        return maxSum;
    }
};