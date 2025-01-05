class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>s;
        vector<int>ans;
        int n = grid.size();
        int a=-1,b=-1;
        int expectedsum = (n*n) * (n*n + 1)/2;
        int actualsum = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                actualsum+=grid[i][j];

                if(s.find(grid[i][j])!=s.end()){
                    a = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }
        b = expectedsum+a-actualsum;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};