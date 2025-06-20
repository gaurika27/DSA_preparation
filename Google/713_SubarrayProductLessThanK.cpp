class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // edge case, any product ≥ 1 will be >= k
        
        int res = 0, l = 0;
        int curr = 1; 
        for (int r = 0; r < nums.size(); r++) {
            curr *= nums[r];

            while (curr >= k && l <= r) {
                curr /= nums[l];
                l++;
            }

            res += r - l + 1;
        }        
        return res;
    }
};
