class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }

        for(auto &iterate:freq){
            if(iterate.second > 1){
                return true;
            }
        }
        return false;
    }
};