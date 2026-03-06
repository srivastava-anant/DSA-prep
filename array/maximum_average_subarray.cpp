class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double cursum = 0;
     for(int i = 0;i<k;i++){
        cursum +=nums[i];

     }  
     double maxsum = cursum;
     for(int i = k;i<nums.size();i++){
        cursum += nums[i] - nums[i - k];
        maxsum = max(maxsum,cursum);
     }
     return maxsum/k;
    }
};
