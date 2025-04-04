class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) {
            return result;
        }
        
        int direction = (k > 0) ? 1 : -1;
        int absK = abs(k);
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 1; j <= absK; j++) {
                sum += code[(i + j * direction + n) % n];
            }
            result[i] = sum;
        }
        
        return result;
    }
};