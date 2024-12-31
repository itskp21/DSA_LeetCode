class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::set<int, std::greater<int>> uniqueNumbers; // Stores unique numbers in descending order

    // Add all numbers to the set
        for (int num : nums) {
            uniqueNumbers.insert(num);
        }

        // Check if there are at least three distinct numbers
        if (uniqueNumbers.size() < 3) {
            return *uniqueNumbers.begin(); // Return the maximum number
        }

        // Iterate to the third maximum number
        auto it = uniqueNumbers.begin();
        std::advance(it, 2);
        return *it;
    }
};