class Solution {
public:
bool canfinish(vector<int> &piles ,int h , int k){
    long long totalHours = 0;
    for(int pile : piles){
        totalHours += (pile + k - 1) / k;
    }
    return totalHours <=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int pile : piles) high = max(high, pile);

        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canfinish(piles, h, mid)) {
                result = mid;      
                high = mid - 1;    
            } else {
                low = mid + 1;     
            }
        }
        return result;
    }
};
