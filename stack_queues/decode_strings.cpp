class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int num = 0;
        string curr = "";

        for(char ch : s) {

            if(isdigit(ch)) {
                // build number (could be multiple digits)
                num = num * 10 + (ch - '0');
            }
            else if(ch == '[') {
                // push current string and number
                st.push(curr);
                st.push(to_string(num));

                // reset
                curr = "";
                num = 0;
            }
            else if(ch == ']') {
                // get number
                int k = stoi(st.top());
                st.pop();

                // get previous string
                string prev = st.top();
                st.pop();

                // repeat current string k times
                string temp = "";
                for(int i = 0; i < k; i++) {
                    temp += curr;
                }

                // combine
                curr = prev + temp;
            }
            else {
                // normal character
                curr += ch;
            }
        }

        return curr;
    }
};
