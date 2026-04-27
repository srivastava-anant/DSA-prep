class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(!st.empty() && st.top() == ch) {
                st.pop();   // remove duplicate
            } else {
                st.push(ch);
            }
        }

        // build result
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};;
