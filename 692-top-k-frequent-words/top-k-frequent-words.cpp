class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const auto& word : words) {
            count[word]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> maxheap(comp);

        for (const auto& entry : count) {
            maxheap.push({entry.second, entry.first});
        }

        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return result;
    }
};