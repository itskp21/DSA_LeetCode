class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int num:arr){
            freq[num]++;
        }

        unordered_set<int>st;
        for(auto &it : freq){
            int present = it.second;
            if(st.find(present)!=st.end()){
                return false;
            }
            st.insert(present);
        }
        return true;
    }
};