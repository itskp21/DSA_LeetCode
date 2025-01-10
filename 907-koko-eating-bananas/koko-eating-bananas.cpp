class Solution {
public:
    bool CanEatAll(vector<int>&piles,int n,int h,int mid){
        long long actualhours = 0;
        for(int &x:piles){
            actualhours += x/mid;

            if(x%mid!=0){
                actualhours++;
            }
        }
        return actualhours<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(begin(piles),end(piles));
        int res = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(CanEatAll(piles,n,h,mid)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};