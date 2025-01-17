class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int& a : asteroids) {
            bool exploded = false;
            while (!st.empty() && a < 0 && st.top() > 0) {
                int sum = st.top() + a;
                if (sum < 0) {  
                    st.pop();
                } else if (sum > 0) {  
                    exploded = true;
                    break;
                } else {  
                    st.pop();
                    exploded = true;
                    break;
                }
            }
            if (!exploded) {
                st.push(a);  
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};