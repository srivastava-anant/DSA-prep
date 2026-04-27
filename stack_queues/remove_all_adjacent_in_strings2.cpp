class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for(char ch : s) {
            if(!st.empty() && st.top().first == ch) {
                st.top().second++;   // increase count

                if(st.top().second == k) {
                    st.pop();        // remove k duplicates
                }
            } else {
                st.push({ch, 1});    // new character
            }
        }

        // build result
        string res = "";
        while(!st.empty()) {
            char ch = st.top().first;
            int count = st.top().second;
            st.pop();

            res = string(count, ch) + res;
        }

        return res;
    }
};
