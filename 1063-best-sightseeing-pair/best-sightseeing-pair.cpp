class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       int maxScore = 0;
        int maxPrevValue = values[0]; 

        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxPrevValue + values[j] - j);
            maxPrevValue = max(maxPrevValue, values[j] + j);
        }

        return maxScore; 
    }
};