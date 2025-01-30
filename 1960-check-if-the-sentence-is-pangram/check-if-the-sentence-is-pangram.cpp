class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0;

        for (char ch : sentence) {
            mask |= (1 << (ch - 'a')); 
        }

        return mask == (1 << 26) - 1;
    }
};