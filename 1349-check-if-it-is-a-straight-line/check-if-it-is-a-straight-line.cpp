class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n  = coordinates.size();

        int dy_coordinates = coordinates[1][1] - coordinates[0][1];
        int dx_coordinates = coordinates[1][0] - coordinates[0][0];

        for(int i = 2;i<n;i++){
           int dy_i_coordinate = coordinates[i][1] - coordinates[0][1];
           int dx_i_coordinate = coordinates[i][0] - coordinates[0][0];

            if(dy_i_coordinate * dx_coordinates != dx_i_coordinate * dy_coordinates ){
                return false;
            }
        }
        return true;
    }
};