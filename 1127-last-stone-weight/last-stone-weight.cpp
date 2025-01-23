class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap(stones.begin(),stones.end());

        while(maxheap.size()>1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if(x!=y){
                int sum = abs(x-y);
                maxheap.push(sum);
            }
        }
        if(maxheap.empty()){
            return 0;
        }
        else{
            return maxheap.top();
        }
    }
};