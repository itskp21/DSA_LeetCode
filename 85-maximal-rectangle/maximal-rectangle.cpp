class Solution {
public:
    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n), width(n), area(n);
        stack<pair<int, int>> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                left[i] = -1;
            } else {
                left[i] = stk.top().second;
            }
            stk.push({heights[i], i});
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top().first >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                right[i] = n;
            } else {
                right[i] = stk.top().second;
            }
            stk.push({heights[i], i});
        }

        for (int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
            area[i] = width[i] * heights[i];
        }

        return *max_element(area.begin(), area.end());
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, MAH(heights));
        }

        return maxArea;
    }
};