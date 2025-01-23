class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxheap(piles.begin(), piles.end());
        int sum = accumulate(piles.begin(), piles.end(), 0);

        for (int i = 0; i < k; i++) {
            int max_el = maxheap.top();
            maxheap.pop();
            int remove = max_el / 2;
            sum -= remove;
            maxheap.push(max_el - remove);
        }

        return sum;
    }
};