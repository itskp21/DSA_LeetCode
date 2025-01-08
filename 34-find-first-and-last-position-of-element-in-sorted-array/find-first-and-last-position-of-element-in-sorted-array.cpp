class Solution {
public:
    int firstindex(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int first = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid -1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return first;
    }
    int lastindex(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int last = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid +1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstindex(nums,target);
        int last = lastindex(nums,target);

        if(first==-1){
            return {-1,-1};
        }
        else{
            return{first,last};
        }
    }
};