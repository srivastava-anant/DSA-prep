class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // stack stores decreasing elements
        stack<int> st;

        // map: element -> its next greater element
        unordered_map<int,int> mp;

        // Step 1: process nums2
        for(int num : nums2){

            // resolve waiting elements
            while(!st.empty() && num > st.top()){
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // remaining elements have no greater element
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }

        // Step 2: build answer for nums1
        vector<int> ans;
        for(int x : nums1){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
