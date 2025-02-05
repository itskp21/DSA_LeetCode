class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        vector<int> mismatchIndices;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                mismatchIndices.push_back(i);
            }
        }

        if (mismatchIndices.empty()) {
            return true;
        }

        if (mismatchIndices.size() == 2) {
            int first = mismatchIndices[0];
            int second = mismatchIndices[1];
            return (s1[first] == s2[second] && s1[second] == s2[first]);
        }

        return false;
    }
};