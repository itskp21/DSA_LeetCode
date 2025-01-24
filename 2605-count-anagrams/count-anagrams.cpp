class Solution {
public:
    const int MOD = 1000000007;
    long long factorial(int n) {
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }
    long long modInverse(long long x) {
        long long res = 1;
        long long exp = MOD - 2;  // Fermat's Little Theorem
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long distinctAnagramsOfWord(string word) {
    unordered_map<char, int> freq;
    for (char c : word) {
        freq[c]++;
    }
    
    long long res = factorial(word.length());
    
        for (auto& p : freq) {
            res = (res * modInverse(factorial(p.second))) % MOD;
        }
        
        return res;
    }

    int countAnagrams(string s) {
        vector<string> words;
        string word = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        
        long long result = 1;
        
        for (string word : words) {
            result = (result * distinctAnagramsOfWord(word)) % MOD;
        }
        
        return result;
    }
};