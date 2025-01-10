class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for (const auto& flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }

        // Sort start and end times
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> result;
        for (int arrival : people) {
            // Count flowers that have started blooming by arrival
            int bloomCount = upper_bound(start.begin(), start.end(), arrival) - start.begin();
            // Count flowers that have already ended blooming by arrival
            int endCount = lower_bound(end.begin(), end.end(), arrival) - end.begin();
            result.push_back(bloomCount - endCount);
        }

        return result;
    }
};