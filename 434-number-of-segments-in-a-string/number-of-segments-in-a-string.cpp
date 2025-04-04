class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;

        for (char c : s) {
            if (c != ' ') {
                if (!inSegment) {
                    inSegment = true;
                    count++;
                }
            } else {
                inSegment = false;
            }
        }
        return count;
    }
};