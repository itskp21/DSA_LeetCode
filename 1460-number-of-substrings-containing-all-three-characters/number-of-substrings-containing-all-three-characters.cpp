class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> count; 
        int left = 0, result = 0, n = s.size();

        for (int right = 0; right < n; ++right) {
            count[s[right]]++;

            while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
                result += (n - right); 
                count[s[left]]--;
                left++;
            }
        }
        return result;
    }
};