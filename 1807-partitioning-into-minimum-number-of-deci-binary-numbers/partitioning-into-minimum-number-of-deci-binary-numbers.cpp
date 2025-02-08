class Solution {
public:
    int minPartitions(string n) {
        char max_digit = *max_element(n.begin(), n.end());
        return max_digit - '0';
    }
};