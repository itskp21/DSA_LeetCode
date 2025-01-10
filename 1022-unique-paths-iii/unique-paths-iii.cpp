class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0, emptySquares = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0) {
                    ++emptySquares;
                }
            }
        }
        return dfs(grid, startX, startY, emptySquares + 1);
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int remainingSquares) {
        // Boundary checks and obstacle checks
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }

        // If we reach the ending square
        if (grid[x][y] == 2) {
            return remainingSquares == 0 ? 1 : 0;
        }

        // Mark the current square as visited
        grid[x][y] = -1;

        // Explore all four directions
        int totalPaths = dfs(grid, x + 1, y, remainingSquares - 1)
                       + dfs(grid, x - 1, y, remainingSquares - 1)
                       + dfs(grid, x, y + 1, remainingSquares - 1)
                       + dfs(grid, x, y - 1, remainingSquares - 1);

        // Backtrack: Mark the square as unvisited
        grid[x][y] = 0;

        return totalPaths;
    }
};