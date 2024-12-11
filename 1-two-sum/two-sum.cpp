class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num;

        for(int i =0;i<nums.size();i++){
            int complement = target - nums[i];
            if(num.find(complement)!=num.end()){
                return {num[complement],i};
            }
            num[nums[i]] = i;
        }
        return {};
    }
};