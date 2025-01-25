class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       map<int, int> losses;
       set<int> players;

        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            players.insert(winner);
            players.insert(loser);
            losses[loser]++;
        }

        vector<int> noLosses;
        vector<int> oneLoss;

        for (int player : players) {
            if (losses[player] == 0) {
                noLosses.push_back(player);
            } else if (losses[player] == 1) {
                oneLoss.push_back(player);
            }
        }

        sort(noLosses.begin(), noLosses.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {noLosses, oneLoss}; 
    }
};