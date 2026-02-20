class Solution {
public:

    bool canDistribute(vector<int>& quantities, int n, int x) {
        long long stores = 0;

        for (int q : quantities) {
            stores += (q + x - 1) / x;  

            if (stores > n)
                return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, n, mid)) {
                ans = mid;        
                high = mid - 1;
            }
            else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};

