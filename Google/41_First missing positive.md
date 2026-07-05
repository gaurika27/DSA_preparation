### M1- Brute force method
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target=1;
        for(int i=0; i<nums.size(); i++){
          if(n>0 && n==target) target++;
          else if(n<target) return target;
        }
        return target;
    }
};
```
