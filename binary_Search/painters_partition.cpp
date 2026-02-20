class Solution {
  public:

    bool canPaint(vector<int>& arr, int k, int maxTime) {
        int painters = 1;
        int currTime = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] > maxTime)
                return false;

            if (currTime + arr[i] <= maxTime) {
                currTime += arr[i];
            } else {
                painters++;
                currTime = arr[i];
            }

            if (painters > k)
                return false;
        }

        return true;
    }

    int minTime(vector<int>& arr, int k) {

        int low = *max_element(arr.begin(), arr.end());
        int high = 0;

        for (int x : arr)
            high += x;

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

