class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts; 
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; ++i) {
            starts.push_back({intervals[i][0], i});
        }
        
        sort(starts.begin(), starts.end());
        
        for (int i = 0; i < n; ++i) {
            int end = intervals[i][1];
            
            int left = 0, right = n - 1, idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= end) {
                    idx = starts[mid].second;
                    right = mid - 1; 
                } else {
                    left = mid + 1;
                }
            }
            
            result[i] = idx;
        }
        
        return result;
    }
};