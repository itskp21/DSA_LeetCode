class Solution {
public:
    bool canAllocate(const vector<int>& candies, long long k, int mid) { // Fix: use long long for k
        long long count = 0; // Fix: use long long to avoid overflow
        for (int candy : candies) {
            count += candy / mid;
            if (count >= k) return true; // Early exit optimization
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (k == 0) return 0;
    
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canAllocate(candies, k, mid)) {
                result = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return result;
    }
};
