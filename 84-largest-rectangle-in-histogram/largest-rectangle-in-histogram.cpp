class Solution {
public:
    vector<int> leftidx(vector<int> &heights){
        int n = heights.size();
        vector<int> left;
        stack<pair<int,int>> stk;

        for(int i =0;i<n;i++){
            while(!stk.empty()&&stk.top().first>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(stk.top().second);
            }
            stk.push({heights[i],i});
        }
        return left;
    }
    vector<int> rightidx(vector<int> &heights){
        vector<int> right(heights.size());
        stack<pair<int,int>> stk;
        int n = heights.size();

        for(int i=heights.size()-1;i>=0;i--){
            while(!stk.empty()&&stk.top().first>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                right[i] = heights.size();
            }
            else{
                right[i] = stk.top().second;
            }
            stk.push({heights[i],i});
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right = rightidx(heights);
        vector<int> left = leftidx(heights);
        vector<int> width(heights.size());
        vector<int> area(heights.size());
        for(int i = 0;i<heights.size();i++){
            width[i]  = right[i] - left[i] -1;
        }
        for(int i = 0;i<heights.size();i++){
            area[i] = width[i] * heights[i];
        }

        return *max_element(area.begin(),area.end());
    }
};