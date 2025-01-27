class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res = "";
        string res2 = "";

        for(auto &c:word1){
            res+=c;
        }
        for(auto &d:word2){
            res2+=d;
        }

        if(res == res2){
            return true;
        }
        else{
            return false;
        }
    }
};