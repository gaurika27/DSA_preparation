class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0, maxsum=INT_MIN;
        for(auto it:nums){
            currsum+=it;
            maxsum=max(currsum,maxsum);
            if(currsum<0) currsum=0;
        }        
        return maxsum;
    }
};