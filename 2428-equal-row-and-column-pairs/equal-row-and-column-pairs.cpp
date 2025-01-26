class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> mp;

        for (int row = 0; row < n; row++) {
            mp[grid[row]]++;
        }

        for (int col = 0; col < n; col++) {
            vector<int> temp;
            for (int r = 0; r < n; r++) {
                temp.push_back(grid[r][col]);
            }
            if (mp.find(temp) != mp.end()) {
                count += mp[temp];
            }
        }
        return count;
    }
};