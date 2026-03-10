class Solution {
public:
    int search(vector<int>& nums, int target) {
     int left = 0 ;
     int high = nums.size() -1;
     while(left<high){
        int mid = left +(high-left+1)/2;
        if(target<nums[mid]){
            high = mid-1;
        }
        else
        left = mid;
     }   
     if (nums[left] == target) {
    return left;  
} else {
    return -1;    
}
    }
};
