class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>> maxheap;

        for(int i =0;i<n;i++){
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxheap.push({distance,{points[i][0],points[i][1]}});

            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<vector<int>>ans;
        while(!maxheap.empty()){
            pair<int, int> point = maxheap.top().second;
            ans.push_back({point.first, point.second});
            maxheap.pop();
        }
        return ans;
    }
};