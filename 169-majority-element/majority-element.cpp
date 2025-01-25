class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(auto &pair:freq){
            if(pair.second > nums.size()/2){
                return pair.first;
            }
        }
        return -1;
    }
};