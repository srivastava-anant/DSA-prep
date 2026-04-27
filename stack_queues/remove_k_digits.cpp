class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // Step 1: process digits
        for(char digit : num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Step 2: remove remaining k digits
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Step 3: build result efficiently
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());  // push at end
            st.pop();
        }

        reverse(res.begin(), res.end());  // fix order

        // Step 4: remove leading zeros
        int i = 0;
        while(i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);

        // Step 5: edge case
        return res.empty() ? "0" : res;
    }
};
