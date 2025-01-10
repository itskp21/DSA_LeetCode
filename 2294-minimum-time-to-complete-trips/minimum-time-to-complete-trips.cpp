class Solution {
public:
    bool canCompleteTrips(const vector<int>& time, long long mid, int totalTrips) {
        long long tripsCompleted = 0;
        for (int t : time) {
            tripsCompleted += mid / t;
            if (tripsCompleted >= totalTrips) return true;
        }
        return tripsCompleted >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = (long long) *max_element(time.begin(), time.end()) * totalTrips;
    
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canCompleteTrips(time, mid, totalTrips)) {
                high = mid; 
            } else {
                low = mid + 1; 
            }
        }
        return low;
        }
};