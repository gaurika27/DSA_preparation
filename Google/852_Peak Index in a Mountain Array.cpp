class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size()-1, n=arr.size();
        for(auto it: arr){
            int mid=(low+high)>>1;
            if(arr[mid]>arr[mid+1]) high=mid;
            else low=mid+1;
        }        
        return low;
    }
};