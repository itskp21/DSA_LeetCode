class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; i++) {
            workers.emplace_back((double)wage[i] / quality[i], quality[i]);
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = DBL_MAX;

        for (auto& [ratio, q] : workers) {
            maxHeap.push(q);
            qualitySum += q;

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                double cost = qualitySum * ratio;  
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};